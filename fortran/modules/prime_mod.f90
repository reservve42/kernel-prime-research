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


module prime_mod
    implicit none
contains
    function is_prime(n) result(res)
        integer(kind=8), intent(in) :: n
        logical :: res
        integer(kind=8) :: i
        if (n < 2) then
            res = .false.
            return
        else if (n == 2) then
            res = .true.
            return
        else if (mod(n,2) == 0) then
            res = .false.
            return
        end if
        res = .true.
        do i = 3, int(sqrt(real(n,8))), 2
            if (mod(n,i) == 0) then
                res = .false.
                return
            end if
        end do
    end function is_prime
end module prime_mod

