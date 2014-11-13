target remote |openocd -c "gdb_port pipe" -f cc3200.cfg
load
set $sp = g_pfnVectors[0]
set $pc = g_pfnVectors[1]
break main
continue
