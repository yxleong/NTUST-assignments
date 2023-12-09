;; Define a function named inv_app which takes list1 and list2 as input
(define (inv_app list1 list2)
  ;; Use append to concatenate the reversed list2 and reversed list1
  (append (reverse list2) (reverse list1))
)

;; Define the lists
(define list1 '(1 2 3))
(define list2 '(a b c))
;; Use the inv_app function
(define result (inv_app list1 list2))
;; Display the result
(display result)