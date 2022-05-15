// Data members
//------------------------------------------------------------------------------
Float_t value_1 = 3.3910;
Float_t error_1 = 0.0018;
Float_t value_2 = 3.350;
Float_t error_2 = 0.002;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// main
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void lfi_errores()
{
  Float_t difference = fabs(value_1 - value_2);

  Float_t difference_error = sqrt(error_1*error_1 + error_2*error_2);

  Float_t difference_significance = difference / difference_error;

  Float_t relative_difference = 1e2 * difference / ((value_1 + value_2) / 2.);


  printf("\n");
  printf("                 value 1 = %6.4f +- %6.4f\n", value_1, error_1);
  printf("                 value 2 = %6.4f +- %6.4f\n", value_2, error_2);
  printf("              difference = %6.4f +- %6.4f\n", difference, difference_error);
  printf(" difference significance = difference / difference_error = %.1f\n", difference_significance);
  printf("     relative difference = %.2f%s\n", relative_difference, "%");
  printf("\n");
}
