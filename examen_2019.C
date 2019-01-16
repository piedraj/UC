// Data members
//------------------------------------------------------------------------------
Float_t error_mass     = 0.001;  // kg
Float_t error_pressure =     1;  // Pa
Float_t gravity        =  9.81;  // m/s^2
Float_t surface        = 0.016;  // m^2
Float_t density        =   1.2;  // kg/m^3

Float_t coefficient[2];
Float_t error_coefficient[2];


// Function members
//------------------------------------------------------------------------------
void elevation_coefficient(TString conditions,
			   Int_t   index,
			   Float_t mass,
			   Float_t pressure);


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// main
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void examen_2019()
{
  printf("\n");

  elevation_coefficient("max power", 0, 0.062, 60);
}


void elevation_coefficient(TString conditions,
			   Int_t   index,
			   Float_t mass,
			   Float_t pressure)
{
  Float_t force = gravity * mass;

  Float_t velocity = sqrt(2. * pressure / density);

  Float_t error_velocity = (velocity / 2.) * (error_pressure / pressure);

  Float_t v_coefficient = (2. * force) / (density * velocity * velocity * surface);

  Float_t v_error_coefficient = v_coefficient * sqrt((error_mass/mass)*(error_mass/mass) + 4.*(error_velocity/velocity)*(error_velocity/velocity));

  coefficient[index] = (gravity / surface) * (mass / pressure);

  error_coefficient[index] = coefficient[index] * sqrt((error_mass/mass)*(error_mass/mass) + (error_pressure/pressure)*(error_pressure/pressure));

  printf("   %s\n", conditions.Data());
  printf("   ---------\n");
  printf("         pressure = %2.0f +- %1.0f Pa\n", pressure, error_pressure);
  printf("             mass = %.3f +- %.3f kg\n", mass, error_mass);
  printf(" coefficient (v1) = %.3f +- %.3f\n", coefficient[index], error_coefficient[index]);
  printf(" coefficient (v2) = %.3f +- %.3f\n", v_coefficient, v_error_coefficient);
  printf("         velocity = %.2f +- %.2f m/s\n", velocity, error_velocity);
  printf("            force = %.3f N\n", force);
  printf("\n");
}
