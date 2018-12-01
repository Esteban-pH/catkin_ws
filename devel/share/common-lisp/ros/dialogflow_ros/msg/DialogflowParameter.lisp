; Auto-generated. Do not edit!


(cl:in-package dialogflow_ros-msg)


;//! \htmlinclude DialogflowParameter.msg.html

(cl:defclass <DialogflowParameter> (roslisp-msg-protocol:ros-message)
  ((name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (value
    :reader value
    :initarg :value
    :type cl:string
    :initform ""))
)

(cl:defclass DialogflowParameter (<DialogflowParameter>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DialogflowParameter>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DialogflowParameter)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dialogflow_ros-msg:<DialogflowParameter> is deprecated: use dialogflow_ros-msg:DialogflowParameter instead.")))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <DialogflowParameter>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dialogflow_ros-msg:name-val is deprecated.  Use dialogflow_ros-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <DialogflowParameter>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dialogflow_ros-msg:value-val is deprecated.  Use dialogflow_ros-msg:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DialogflowParameter>) ostream)
  "Serializes a message object of type '<DialogflowParameter>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'value))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DialogflowParameter>) istream)
  "Deserializes a message object of type '<DialogflowParameter>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'value) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'value) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DialogflowParameter>)))
  "Returns string type for a message object of type '<DialogflowParameter>"
  "dialogflow_ros/DialogflowParameter")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DialogflowParameter)))
  "Returns string type for a message object of type 'DialogflowParameter"
  "dialogflow_ros/DialogflowParameter")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DialogflowParameter>)))
  "Returns md5sum for a message object of type '<DialogflowParameter>"
  "bc6ccc4a57f61779c8eaae61e9f422e0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DialogflowParameter)))
  "Returns md5sum for a message object of type 'DialogflowParameter"
  "bc6ccc4a57f61779c8eaae61e9f422e0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DialogflowParameter>)))
  "Returns full string definition for message of type '<DialogflowParameter>"
  (cl:format cl:nil "string name~%string value~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DialogflowParameter)))
  "Returns full string definition for message of type 'DialogflowParameter"
  (cl:format cl:nil "string name~%string value~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DialogflowParameter>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'name))
     4 (cl:length (cl:slot-value msg 'value))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DialogflowParameter>))
  "Converts a ROS message object to a list"
  (cl:list 'DialogflowParameter
    (cl:cons ':name (name msg))
    (cl:cons ':value (value msg))
))
