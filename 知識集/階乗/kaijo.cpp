int kaijo(int a) {
  if(a == 0) return kaijo(a);
  return a * kaijo(a-1);
}
