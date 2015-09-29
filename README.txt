Name:Yutong Liu
Student Number :55236137
Lab L0C
h1y8

The basic idea of this program is using recursion.Overall, there are four cases: no way to go, one way, two ways and three ways. When there is no way to go, we need to check if the column of that point is 14 or not. If it is 14, meaning the path is valid and we print it out. Otherwise, the path is invalid and we do not print it. One way is easy to implement, you just need to check left,right,up and down and add the corresponding alphabet to the path. Two way is just the recursion of one way.You see two ways to go,for example (right and left).First you copy the old path to a new path,then you add the rightside alphabet to the array and call generate_all_paths on old path(this function will give you back the rightside path after the ramification point).Next,add the leftside alphabet to the arrat and call generate_all_paths on new path.(this function will give you back the leftside path after the ramification point).Three way case works the same as two way case. Each time you see another way, you copy the path array to a new array.
