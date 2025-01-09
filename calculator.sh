echo "Enter 1st number:"
read x
echo "Enter 2nd number:"
read y 
echo "Menu: 1.Add   2.Subtraction   3.Multiplication   4.Division"
read op
case $op in 
	1) rs=$(($x+$y))
	   echo "Sum="$rs;;
	2) rs=$(($x-$y))
	   echo "Difference="$rs;;
	3) rs=$(($x*$y))
	   echo "Product="$rs;;
	4) rs=$(($x/$y))
	   echo "Quotient="$rs;;
	*) echo "Invalid operation!";;
esac	
	   
