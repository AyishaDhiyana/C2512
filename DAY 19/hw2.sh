002) Pattern Printing 

solution : 
#!/bin/bash

rows=4

for (( I = 1; I <= $rows; I++ )); do
        for (( J = 1; J <= I; J++ )); do
                echo -n "$J"
        done
        echo
done
