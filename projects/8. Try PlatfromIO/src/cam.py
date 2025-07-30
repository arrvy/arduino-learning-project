import cv2
import mediapipe as mp
import requests
# ESP32 Base URL
ESP32_IP = "http://192.168.10.190"   # Change this to your ESP32 IP address
# Initialize MediaPipe Hands
mp_hands = mp.solutions.hands
hands = mp_hands.Hands()
mp_drawing = mp.solutions.drawing_utils
# Function to send hand gesture commands to ESP32
def control_led(endpoint):
   url = f"{ESP32_IP}/led/{endpoint}"
   try:
       response = requests.get(url)
       print(f"Sent command: {endpoint}, ESP32 Response: {response.text}")
   except Exception as e:
       print(f"Failed to send command: {endpoint}, Error: {e}")
# Function to fetch commands from ESP32
def fetch_esp32_command():
   try:
       url = f"{ESP32_IP}/command"
       response = requests.get(url)
       return response.text.strip()
   except Exception as e:
       print(f"Error fetching command from ESP32: {e}")
       return None
# Function to detect the state of each finger
def count_fingers(hand_landmarks):
   # Detect finger states (up or down)
   thumb_up = hand_landmarks.landmark[mp_hands.HandLandmark.THUMB_TIP].x < hand_landmarks.landmark[mp_hands.HandLandmark.THUMB_IP].x
   index_up = hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP].y < hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_PIP].y
   middle_up = hand_landmarks.landmark[mp_hands.HandLandmark.MIDDLE_FINGER_TIP].y < hand_landmarks.landmark[mp_hands.HandLandmark.MIDDLE_FINGER_PIP].y
   ring_up = hand_landmarks.landmark[mp_hands.HandLandmark.RING_FINGER_TIP].y < hand_landmarks.landmark[mp_hands.HandLandmark.RING_FINGER_PIP].y
   pinky_up = hand_landmarks.landmark[mp_hands.HandLandmark.PINKY_TIP].y < hand_landmarks.landmark[mp_hands.HandLandmark.PINKY_PIP].y
   # Combine finger statuses into a list
   finger_status = [thumb_up, index_up, middle_up, ring_up, pinky_up]
   # Send control commands to ESP32 for each finger

   # ! Kekurangan kode sebellumnya ternyata si dia belum nulis perintah per jari
   control_led("add" if thumb_up else "remove")
   control_led("thumb/on" if index_up else "thumb/off")
   control_led("index/on" if index_up else "index/off")
   control_led("middle/on" if middle_up else "middle/off")
   control_led("ring/on" if middle_up else "ring/off")
   control_led("pinky/on" if middle_up else "pinky/off")
   # Check if all fingers are down
   if not any(finger_status):
       print("All fingers are down")  # Message when all fingers are down
       control_led("all/down")  # Example action when all fingers are down
   return finger_status
# Initialize VideoCapture
cap = cv2.VideoCapture(0)
while cap.isOpened():
   ret, frame = cap.read()
   if not ret:
       break
   frame = cv2.flip(frame, 1)
   frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
   # Detect hand landmarks
   results = hands.process(frame_rgb)
   if results.multi_hand_landmarks:
       for hand_landmarks in results.multi_hand_landmarks:
           mp_drawing.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)
           fingers = count_fingers(hand_landmarks)
   # Fetch and display command from ESP32
   esp32_command = fetch_esp32_command()
   if esp32_command:
       cv2.putText(frame, f"ESP32 Command: {esp32_command}", (10, 50), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 255, 0), 2)
   cv2.imshow('Hand Gesture Recognition', frame)
   if cv2.waitKey(5) & 0xFF == 27:  # Exit on pressing 'Esc'
       break
cap.release()
cv2.destroyAllWindows()