//------------------------------------------------------------------------------
//
// root -l fit_pol1.C
//
//------------------------------------------------------------------------------

void fit_pol1()
{
  const Int_t n = 6;

  Double_t vx[n] = {6.235, 8.105, 9.97, 11.815, 13.6574, 15.4921};
  Double_t vy[n] = {log(343.3), log(229), log(147.2), log(89.8), log(50.2), log(24.3)};
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
