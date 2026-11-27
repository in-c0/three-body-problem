module three_body
contains
    subroutine compute() bind(C, name="compute")
        use iso_c_binding
        implicit none
        print *, "Running Fortran computation"
    end subroutine compute
end module three_body
