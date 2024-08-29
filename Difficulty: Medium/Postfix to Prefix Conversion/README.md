<h2><a href="https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postfix-to-prefix-conversion">Postfix to Prefix Conversion</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p dir="ltr"><span style="font-size: 18px;">You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.</span></p>
<p dir="ltr"><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> 
ABC/-AK/L-*
<strong>Output: </strong>
*-A/BC-/AKL
<strong>Explanation:</strong> 
The above output is its valid prefix form.<br><br></span></pre>
<p dir="ltr" style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif; font-size: medium; white-space: normal;"><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><strong>Input:</strong> 
ab+
<strong>Output: </strong>
+ab
<strong>Explanation:</strong> 
The above output is its valid prefix form.</pre>
<p dir="ltr"><span style="font-size: 18px;"><strong>Your Task:</strong></span></p>
<p dir="ltr"><span style="font-size: 18px;">Complete the function <strong>string postToPre(string post_exp)</strong>, which takes a postfix string as input and returns its prefix form.</span></p>
<p dir="ltr"><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(</span><span style="font-size: 18px;">post_exp.length()</span><span style="font-size: 18px;">).</span></p>
<p dir="ltr"><span style="font-size: 18px;"><strong>Expected Auxiliary Space:</strong> O(</span><span style="font-size: 18px;">post_exp.length()</span><span style="font-size: 18px;">).</span></p>
<p dir="ltr"><span style="font-size: 18px;"><strong>Constraints:</strong></span></p>
<p dir="ltr"><span style="font-size: 18px;">3&lt;=post_exp.length()&lt;=16000</span></p></div>