#lang racket

(define (mySqrt x y)
  (if (< (Fabs (- (* y y) x)) eps)
	y
	(mySqrt x (/ (+ (/ x y) y) 2.0)))
  )

(define eps 1e-8)

(define (Fabs x)
  (if (< x 0)
	(- x)
	x)
  )

(mySqrt 9.0 1.0)
