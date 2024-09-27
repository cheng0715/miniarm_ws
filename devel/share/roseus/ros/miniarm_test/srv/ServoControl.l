;; Auto-generated. Do not edit!


(when (boundp 'miniarm_test::ServoControl)
  (if (not (find-package "MINIARM_TEST"))
    (make-package "MINIARM_TEST"))
  (shadow 'ServoControl (find-package "MINIARM_TEST")))
(unless (find-package "MINIARM_TEST::SERVOCONTROL")
  (make-package "MINIARM_TEST::SERVOCONTROL"))
(unless (find-package "MINIARM_TEST::SERVOCONTROLREQUEST")
  (make-package "MINIARM_TEST::SERVOCONTROLREQUEST"))
(unless (find-package "MINIARM_TEST::SERVOCONTROLRESPONSE")
  (make-package "MINIARM_TEST::SERVOCONTROLRESPONSE"))

(in-package "ROS")





(defclass miniarm_test::ServoControlRequest
  :super ros::object
  :slots (_command ))

(defmethod miniarm_test::ServoControlRequest
  (:init
   (&key
    ((:command __command) "")
    )
   (send-super :init)
   (setq _command (string __command))
   self)
  (:command
   (&optional __command)
   (if __command (setq _command __command)) _command)
  (:serialization-length
   ()
   (+
    ;; string _command
    4 (length _command)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _command
       (write-long (length _command) s) (princ _command s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _command
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _command (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass miniarm_test::ServoControlResponse
  :super ros::object
  :slots (_success _message ))

(defmethod miniarm_test::ServoControlResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:message __message) "")
    )
   (send-super :init)
   (setq _success __success)
   (setq _message (string __message))
   self)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass miniarm_test::ServoControl
  :super ros::object
  :slots ())

(setf (get miniarm_test::ServoControl :md5sum-) "c348f8d8cd3a80f54328aa4159009109")
(setf (get miniarm_test::ServoControl :datatype-) "miniarm_test/ServoControl")
(setf (get miniarm_test::ServoControl :request) miniarm_test::ServoControlRequest)
(setf (get miniarm_test::ServoControl :response) miniarm_test::ServoControlResponse)

(defmethod miniarm_test::ServoControlRequest
  (:response () (instance miniarm_test::ServoControlResponse :init)))

(setf (get miniarm_test::ServoControlRequest :md5sum-) "c348f8d8cd3a80f54328aa4159009109")
(setf (get miniarm_test::ServoControlRequest :datatype-) "miniarm_test/ServoControlRequest")
(setf (get miniarm_test::ServoControlRequest :definition-)
      "string command
---
bool success
string message

")

(setf (get miniarm_test::ServoControlResponse :md5sum-) "c348f8d8cd3a80f54328aa4159009109")
(setf (get miniarm_test::ServoControlResponse :datatype-) "miniarm_test/ServoControlResponse")
(setf (get miniarm_test::ServoControlResponse :definition-)
      "string command
---
bool success
string message

")



(provide :miniarm_test/ServoControl "c348f8d8cd3a80f54328aa4159009109")


