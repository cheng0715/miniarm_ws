
(cl:in-package :asdf)

(defsystem "miniarm_test-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "MoveArm" :depends-on ("_package_MoveArm"))
    (:file "_package_MoveArm" :depends-on ("_package"))
    (:file "ServoControl" :depends-on ("_package_ServoControl"))
    (:file "_package_ServoControl" :depends-on ("_package"))
  ))