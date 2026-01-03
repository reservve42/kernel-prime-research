! Kernel Cryptography Research Project
!
! Low-level cryptography algorithms and protocols
! for Linux kernel experimentation.
! 
! Project focuses on:
!      - Prime number computations
!      - Cryptographic number theory
!      - Computational hardness
!      - Encrypted data handling and protocol tracing (e.g., CP2A)
! 
!  Documentation and research notes are maintained internally.
! 
!  Copyright (c) 2025 Luís Henrique (Heanrig) <henriqueeeee85@gmail.com>
! 
!  This project is intended for research and educational purposes.
!  Redistribution and modification are allowed under GPL-2.0-or-later.


module bigint_mod
    implicit none
    integer, parameter :: dp = selected_int_kind(18)
contains
    function mul(a,b) result(res)
        integer(kind=dp), intent(in) :: a, b
        integer(kind=dp) :: res
        res = a * b
    end function mul
end module bigint_mod
