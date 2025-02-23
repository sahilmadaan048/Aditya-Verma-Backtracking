/*

time complexity 101 
recursive tree time complexity
TC of last solution Big O
dont be too attached



TC 101 => explains rate or nature

between the time taken ans the size of input

best proxy to define time complexity   => work done in function of n which is size of input f(n)




|
|        /    /
|       /    /
|      /    /
|     /    /
|    /    /
|   /    /
|  /    /
| /    /
|/____/____________________


no of nodes in the recursive tree on lth level => pow(2, l-1)
total number of nodes = n
2^) 2^1 + 2^2..........2^l-1 = n;


solvig we get

2^l-1 = n                               

l = log n

total time complexity in recursive tree = #of nodes * time complexity if one node
 
previous problem =
> permuattion onf strings =>    
wrdk done => no of choices - length of string (n)
                            then n-1
                            then n-2 for wch
                                                                    . 
                            . till 1 for each

                            n + (n)(n-1) + .n*n01*n-2 .......*1 = 

                                overall it is n!

                                for(every character we are doing the recursive call)


                                substring method tome comeplexity is o(m)
                            inside for loop

                            o(n^2)

this total TC is O(n^2)*n!



4. dont be too attached




*/                      
