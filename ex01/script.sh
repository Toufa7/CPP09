#!/bin/bash
./rpn "3 2 1 + *"
echo "Output = 16"


./rpn "2 4 8 + *"
echo "Output = 24"

./rpn "2 5 * 4 + 3 2 * 1 + / "
echo "Output = 2"

./rpn "12 * 2 / 5 + 46 * 6 / 8 * 2 / + 2 * 2 -"
echo "Output = 42"

./rpn "89 * 9 - 9 - 9 - 4 - 1 +"
echo "Output = 42"

./rpn "98 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
echo "Output = 42"