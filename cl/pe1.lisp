;;; Iterative version
(defun lp (num)
  (let ((sum 0))
    (loop for i from 1 to (1- num)
       do (if (or (zerop (mod i 3))
          (zerop (mod i 5)))
          (incf sum i)))
    sum))

;;; Recursive version
(defun rc (num)
  (labels ((rec (n sum)
         (if (>= n num)
         sum
         (if (or (zerop (mod n 3))
             (zerop (mod n 5)))
             (rec (1+ n) (+ sum n))
             (rec (1+ n) sum)))))
    (rec 1 0)))
