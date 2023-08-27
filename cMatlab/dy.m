function dydt = dy(t, v, m, cd)
g = 9.81;
dydt = g - (cd / m) * v;