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

