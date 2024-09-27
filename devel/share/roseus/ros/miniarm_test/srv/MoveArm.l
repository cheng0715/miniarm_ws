;; Auto-generated. Do not edit!


(when (boundp 'miniarm_test::MoveArm)
  (if (not (find-package "MINIARM_TEST"))
    (make-package "MINIARM_TEST"))
  (shadow 'MoveArm (find-package "MINIARM_TEST")))
(unless (find-package "MINIARM_TEST::MOVEARM")
  (make-package "MINIARM_TEST::MOVEARM"))
(unless (find-package "MINIARM_TEST::MOVEARMREQUEST")
  (make-package "MINIARM_TEST::MOVEARMREQUEST"))
(unless (find-package "MINIARM_TEST::MOVEARMRESPONSE")
  (make-package "MINIARM_TEST::MOVEARMRESPONSE"))

(in-package "ROS")

(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))




(defclass miniarm_test::MoveArmRequest
  :super ros::object
  :slots (_target_position ))

(defmethod miniarm_test::MoveArmRequest
  (:init
   (&key
    ((:target_position __target_position) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _target_position __target_position)
   self)
  (:target_position
   (&rest __target_position)
   (if (keywordp (car __target_position))
       (send* _target_position __target_position)
     (progn
       (if __target_position (setq _target_position (car __target_position)))
       _target_position)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point _target_position
    (send _target_position :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point _target_position
       (send _target_position :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point _target_position
     (send _target_position :deserialize buf ptr-) (incf ptr- (send _target_position :serialization-length))
   ;;
   self)
  )

(defclass miniarm_test::MoveArmResponse
  :super ros::object
  :slots (_success _message ))

(defmethod miniarm_test::MoveArmResponse
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

(defclass miniarm_test::MoveArm
  :super ros::object
  :slots ())

(setf (get miniarm_test::MoveArm :md5sum-) "506c8e1e4563f2c77c2205a6a765a75c")
(setf (get miniarm_test::MoveArm :datatype-) "miniarm_test/MoveArm")
(setf (get miniarm_test::MoveArm :request) miniarm_test::MoveArmRequest)
(setf (get miniarm_test::MoveArm :response) miniarm_test::MoveArmResponse)

(defmethod miniarm_test::MoveArmRequest
  (:response () (instance miniarm_test::MoveArmResponse :init)))

(setf (get miniarm_test::MoveArmRequest :md5sum-) "506c8e1e4563f2c77c2205a6a765a75c")
(setf (get miniarm_test::MoveArmRequest :datatype-) "miniarm_test/MoveArmRequest")
(setf (get miniarm_test::MoveArmRequest :definition-)
      "geometry_msgs/Point target_position

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
---
bool success
string message

")

(setf (get miniarm_test::MoveArmResponse :md5sum-) "506c8e1e4563f2c77c2205a6a765a75c")
(setf (get miniarm_test::MoveArmResponse :datatype-) "miniarm_test/MoveArmResponse")
(setf (get miniarm_test::MoveArmResponse :definition-)
      "geometry_msgs/Point target_position

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
---
bool success
string message

")



(provide :miniarm_test/MoveArm "506c8e1e4563f2c77c2205a6a765a75c")


