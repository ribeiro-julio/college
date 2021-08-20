global kc
global ti
global td
global y_out
global ti_me

t_end = 30;
h = 0.05;
x0 = [1.2 6 0.75];
x = fminsearch(@fobs,x0,[],t_end,h)


function f=fobs(x,t_end,h)
    global kc
    global ti
    global td
    global y_out
    global ti_me

    kc = x(1);
    ti = x(2);
    td = x(3);
    tt = (0:h:t_end);
    [t, y] = sim('sim_simulink1',tt);
    f = 0;
    l = length(ti_me);
    f = abs(y_out(l,1) - y_out(l,2));
    for i=2:2:l-1
        f = f + 4*abs(y_out(i,1) - y_out(i,2));
    end
    for i=3:2:l-2
        f = f + 2*abs(y_out(i,1) - y_out(i,2));
    end
    f = h/3*f
end