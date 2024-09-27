; Auto-generated. Do not edit!


(cl:in-package miniarm_test-srv)


;//! \htmlinclude MoveArm-request.msg.html

(cl:defclass <MoveArm-request> (roslisp-msg-protocol:ros-message)
  ((target_position
    :reader target_position
    :initarg :target_position
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass MoveArm-request (<MoveArm-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MoveArm-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MoveArm-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name miniarm_test-srv:<MoveArm-request> is deprecated: use miniarm_test-srv:MoveArm-request instead.")))

(cl:ensure-generic-function 'target_position-val :lambda-list '(m))
(cl:defmethod target_position-val ((m <MoveArm-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader miniarm_test-srv:target_position-val is deprecated.  Use miniarm_test-srv:target_position instead.")
  (target_position m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MoveArm-request>) ostream)
  "Serializes a message object of type '<MoveArm-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'target_position) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MoveArm-request>) istream)
  "Deserializes a message object of type '<MoveArm-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'target_position) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MoveArm-request>)))
  "Returns string type for a service object of type '<MoveArm-request>"
  "miniarm_test/MoveArmRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveArm-request)))
  "Returns string type for a service object of type 'MoveArm-request"
  "miniarm_test/MoveArmRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MoveArm-request>)))
  "Returns md5sum for a message object of type '<MoveArm-request>"
  "506c8e1e4563f2c77c2205a6a765a75c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MoveArm-request)))
  "Returns md5sum for a message object of type 'MoveArm-request"
  "506c8e1e4563f2c77c2205a6a765a75c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MoveArm-request>)))
  "Returns full string definition for message of type '<MoveArm-request>"
  (cl:format cl:nil "geometry_msgs/Point target_position~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MoveArm-request)))
  "Returns full string definition for message of type 'MoveArm-request"
  (cl:format cl:nil "geometry_msgs/Point target_position~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MoveArm-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'target_position))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MoveArm-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MoveArm-request
    (cl:cons ':target_position (target_position msg))
))
;//! \htmlinclude MoveArm-response.msg.html

(cl:defclass <MoveArm-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (message
    :reader message
    :initarg :message
    :type cl:string
    :initform ""))
)

(cl:defclass MoveArm-response (<MoveArm-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MoveArm-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MoveArm-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name miniarm_test-srv:<MoveArm-response> is deprecated: use miniarm_test-srv:MoveArm-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <MoveArm-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader miniarm_test-srv:success-val is deprecated.  Use miniarm_test-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <MoveArm-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader miniarm_test-srv:message-val is deprecated.  Use miniarm_test-srv:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MoveArm-response>) ostream)
  "Serializes a message object of type '<MoveArm-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MoveArm-response>) istream)
  "Deserializes a message object of type '<MoveArm-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'message) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'message) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MoveArm-response>)))
  "Returns string type for a service object of type '<MoveArm-response>"
  "miniarm_test/MoveArmResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveArm-response)))
  "Returns string type for a service object of type 'MoveArm-response"
  "miniarm_test/MoveArmResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MoveArm-response>)))
  "Returns md5sum for a message object of type '<MoveArm-response>"
  "506c8e1e4563f2c77c2205a6a765a75c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MoveArm-response)))
  "Returns md5sum for a message object of type 'MoveArm-response"
  "506c8e1e4563f2c77c2205a6a765a75c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MoveArm-response>)))
  "Returns full string definition for message of type '<MoveArm-response>"
  (cl:format cl:nil "bool success~%string message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MoveArm-response)))
  "Returns full string definition for message of type 'MoveArm-response"
  (cl:format cl:nil "bool success~%string message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MoveArm-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MoveArm-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MoveArm-response
    (cl:cons ':success (success msg))
    (cl:cons ':message (message msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MoveArm)))
  'MoveArm-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MoveArm)))
  'MoveArm-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveArm)))
  "Returns string type for a service object of type '<MoveArm>"
  "miniarm_test/MoveArm")