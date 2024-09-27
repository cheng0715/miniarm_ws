; Auto-generated. Do not edit!


(cl:in-package miniarm_test-srv)


;//! \htmlinclude ServoControl-request.msg.html

(cl:defclass <ServoControl-request> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:string
    :initform ""))
)

(cl:defclass ServoControl-request (<ServoControl-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ServoControl-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ServoControl-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name miniarm_test-srv:<ServoControl-request> is deprecated: use miniarm_test-srv:ServoControl-request instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <ServoControl-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader miniarm_test-srv:command-val is deprecated.  Use miniarm_test-srv:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ServoControl-request>) ostream)
  "Serializes a message object of type '<ServoControl-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'command))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'command))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ServoControl-request>) istream)
  "Deserializes a message object of type '<ServoControl-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'command) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'command) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ServoControl-request>)))
  "Returns string type for a service object of type '<ServoControl-request>"
  "miniarm_test/ServoControlRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ServoControl-request)))
  "Returns string type for a service object of type 'ServoControl-request"
  "miniarm_test/ServoControlRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ServoControl-request>)))
  "Returns md5sum for a message object of type '<ServoControl-request>"
  "c348f8d8cd3a80f54328aa4159009109")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ServoControl-request)))
  "Returns md5sum for a message object of type 'ServoControl-request"
  "c348f8d8cd3a80f54328aa4159009109")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ServoControl-request>)))
  "Returns full string definition for message of type '<ServoControl-request>"
  (cl:format cl:nil "string command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ServoControl-request)))
  "Returns full string definition for message of type 'ServoControl-request"
  (cl:format cl:nil "string command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ServoControl-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'command))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ServoControl-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ServoControl-request
    (cl:cons ':command (command msg))
))
;//! \htmlinclude ServoControl-response.msg.html

(cl:defclass <ServoControl-response> (roslisp-msg-protocol:ros-message)
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

(cl:defclass ServoControl-response (<ServoControl-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ServoControl-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ServoControl-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name miniarm_test-srv:<ServoControl-response> is deprecated: use miniarm_test-srv:ServoControl-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <ServoControl-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader miniarm_test-srv:success-val is deprecated.  Use miniarm_test-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <ServoControl-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader miniarm_test-srv:message-val is deprecated.  Use miniarm_test-srv:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ServoControl-response>) ostream)
  "Serializes a message object of type '<ServoControl-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ServoControl-response>) istream)
  "Deserializes a message object of type '<ServoControl-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ServoControl-response>)))
  "Returns string type for a service object of type '<ServoControl-response>"
  "miniarm_test/ServoControlResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ServoControl-response)))
  "Returns string type for a service object of type 'ServoControl-response"
  "miniarm_test/ServoControlResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ServoControl-response>)))
  "Returns md5sum for a message object of type '<ServoControl-response>"
  "c348f8d8cd3a80f54328aa4159009109")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ServoControl-response)))
  "Returns md5sum for a message object of type 'ServoControl-response"
  "c348f8d8cd3a80f54328aa4159009109")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ServoControl-response>)))
  "Returns full string definition for message of type '<ServoControl-response>"
  (cl:format cl:nil "bool success~%string message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ServoControl-response)))
  "Returns full string definition for message of type 'ServoControl-response"
  (cl:format cl:nil "bool success~%string message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ServoControl-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ServoControl-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ServoControl-response
    (cl:cons ':success (success msg))
    (cl:cons ':message (message msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ServoControl)))
  'ServoControl-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ServoControl)))
  'ServoControl-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ServoControl)))
  "Returns string type for a service object of type '<ServoControl>"
  "miniarm_test/ServoControl")