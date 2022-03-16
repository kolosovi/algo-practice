Looks like a DP problem

So basically, I can reach the last index if I can reach any index that's positioned in such a way that I can jump from that index to the last one. So basically I just look at my options from there.

OR it can be framed as a depth-first search problem.

Input: nums = [2,3,1,1,4]

```
0 1 2 3 4
2 3 1 1 4
  * *
```

So from 0 I can go to either 1 or 2. Then I explore further.

I mark a "node" as visited when I exhausted all its children. So it's something like this:

for j := i + 1; j < i + nums[i]; j++ {
    if visited[j] {
        continue
    }
    if j == len(nums) - 1 {
        return true
    }
    ok := visit(j)
    if ok {
        return true
    }
}
visited[i] = true
return false

Better approach: let's say i } j means "j is directly reachable from i" and i }} j means "j is reachable from i, probably not directly".

Let T be the target index (i.e last one).

Let j: j < t and j } T.

Let i: i < j and i }} T.

Let's prove that i }} j. If i } T, then i } j because j < T. If not, then there's some i': i < i' < t such that i' } T and i }} i'. If i' <= j then i' }} j and from this it follows that i }} j. If i' > j then we can repeat the same argument again (there has to be i'' < i' such that i'' } i').

So it's sufficient to repeatedly find the last index that reaches T & assign this index to T. If this process reaches T = 0, then jump from 0 to N-1 is possible. Otherwise it's not.

And this solution is O(N).
