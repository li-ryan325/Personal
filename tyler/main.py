import cv2
from ultralytics import YOLO
from playsound import playsound
import threading

def play_sound(sound_file):
    threading.Thread(target=playsound, args=(sound_file,), daemon=True).start()

model = YOLO('yolov8n.pt')
cap = cv2.VideoCapture(0)

sound_played = False

while True:
    ret, frame = cap.read()

    if not ret:
        break

    results = model(frame)

    boxes = results[0].boxes
    class_ids = boxes.cls

    detected_person = False
    for class_id in class_ids:
        if class_id == 0:
            detected_person = True
            break

    if detected_person and not sound_played:
        print("Person detected")
        play_sound('/home/ryan/Desktop/tyler/fam.mp3')
        sound_played = True

    if not detected_person:
        sound_played = False

    frame = results[0].plot()

    cv2.imshow('YOLOv8 Person Detection', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
