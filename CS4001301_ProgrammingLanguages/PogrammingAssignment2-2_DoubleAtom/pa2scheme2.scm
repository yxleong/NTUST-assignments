;; Define a function named dbl_atm which takes atom and list as input.
(define (dbl_atm atom lst)
  (cond 
    ;; If the list is empty, return an empty list.
    ((null? lst) '())

    ;; If the first element is a list
    ((list? (car lst))
     ;; concatenate the results after apply dbl_atm to its car and cdr parts
     (cons (dbl_atm atom (car lst)) (dbl_atm atom (cdr lst)))
    )

    ;; If the first element is the target atom
    ((eq? atom (car lst))
     ;; double it by cons it twice to the result of dbl_atm on the rest of the list.
     (cons atom (cons atom (dbl_atm atom (cdr lst))))
    )
   
    ;; If the first element is neither a list nor the target atom
    (else
     ;; cons it to the result of dbl_atm on the rest of the list
     (cons (car lst) (dbl_atm atom (cdr lst)))
    )
  )
)

;; Define the atom
(define atom 'a)
;; Define the list
(define list2 '(a (b c a (a d))))
;; Use the dbl_atm function
(define result (dbl_atm atom list2))
;; Display the result
(display result)
