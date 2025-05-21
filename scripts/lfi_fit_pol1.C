//------------------------------------------------------------------------------
//
// root -l lfi_fit_pol1.C
//
//------------------------------------------------------------------------------

void lfi_fit_pol1()
{
  const Int_t n = 6;

  Double_t vx[n] = {7.040, 9.075, 11.115, 13.165, 15.225, 17.285};
  Double_t vy[n] = {log(220), log(181), log(142), log(107), log(72), log(38)};
  Double_t ex[n] = {0.003, 0.003, 0.003, 0.003, 0.003, 0.003};
  Double_t ey[n] = {log(0.3), log(0.3), log(0.3), log(0.3), log(0.3), log(0.3)};

  auto g1 = new TGraphErrors(n, vx, vy, ex, ey);

  TCanvas* c1 = new TCanvas("c1", "c1");

  g1->SetMarkerColor(4);
  g1->SetMarkerStyle(21);
  g1->Draw("ap");

  TF1* f1 = new TF1("f1", "pol1", 6, 16);
  
  f1->SetParameter(0, 0.);
  f1->SetParameter(1,-1e-2);

  g1->Fit(f1, "r");

  f1->Draw("same");

  printf("\n");
}
