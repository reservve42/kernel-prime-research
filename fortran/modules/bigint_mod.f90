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

