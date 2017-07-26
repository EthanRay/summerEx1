# summerEx1
<p>
	<span style="font-size:32px;"><strong>NaiveBayesVideoAdvertisementFilter</strong></span>
</p>
<hr style="height:1px;border:none;border-top:1px solid #185598;" />
<p>
	<span style="color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">利用朴素贝叶斯算法实现视频广告的识别与过滤，并结合Adaboost改进该算法。</span>
</p>
<p>
	<span style="color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; line-height: 24px;"><strong><span style="font-size:18px;">1 Native Bayes Video Advertisement Filter</span></strong></span>
</p>
<hr style="height:1px;border:none;border-top:1px solid #185598;" />
<p>
</p>
<p>
	<span style="color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">假设视频总内容为Wi，广告部分为AD，非广告内容为HAM。 判断一个视频，内容包含的词汇为Wi，判断该段视频是否是广告部分，即计算P（S|Wi）这个条件概率。根据Bayes' theorem：</span>
</p>
<p>
	<span style="color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;"><img src="http://img.blog.csdn.net/20170726092657428" alt="" /><br />
	</span>
</p>
<p>
	<span style="color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;"></span>
</p>
<p style="box-sizing: border-box; margin-top: 0px; margin-bottom: 16px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">
	<span style="box-sizing: border-box; font-weight: 600;">注：</span>&nbsp;程序中，通过计算出Pr(S|W)和Pr(H|W)，比较Pr(S|W)和Pr(H|W)的大小，判断是垃圾邮件还是正常邮件。我们发现Pr(S|W)和Pr(H|W)计算的分母相同，所以我们只需要比较分子即可。
</p>
<p style="box-sizing: border-box; margin-top: 0px; margin-bottom: 16px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">  
	<span style="box-sizing: border-box; font-weight: 600;">但存在两个问题：</span>
</p>
<ol style="box-sizing: border-box; padding-left: 2em; margin-top: 0px; margin-bottom: 16px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">
	<li style="box-sizing: border-box;">
		当词汇不存在时，即ni=0，此时Pr(S|Wi) = 0，会造成P=0，无法比较
	</li>
	<li style="box-sizing: border-box; margin-top: 0.25em;">
		当Pr(S|Wi)较小时，连乘操作会造成下溢出问题
	</li>
</ol>
<p style="box-sizing: border-box; margin-top: 0px; margin-bottom: 16px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">  
	<span style="box-sizing: border-box; font-weight: 600;">解决方案：</span>
</p>
<ul style="box-sizing: border-box; padding-left: 2em; margin-top: 0px; margin-bottom: 16px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">
	<li style="box-sizing: border-box;">
		计算P(Wi|S)和P(Wi|H)时，将所有词汇初始化出现的次数为1，并将分母初始化为2（或根据样本/实际调查结果调整分母的值）。
	</li>
</ul>
<pre style="box-sizing: border-box; font-family: SFMono-Regular, Consolas, 'Liberation Mono', Menlo, Courier, monospace; font-size: 13.6000003814697px; margin-top: 0px; margin-bottom: 16px; font-stretch: normal; line-height: 1.45; word-wrap: normal; padding: 16px; overflow: auto; border-radius: 3px; color: rgb(36, 41, 46); background-color: rgb(246, 248, 250);"><code style="box-sizing: border-box; font-family: SFMono-Regular, Consolas, 'Liberation Mono', Menlo, Courier, monospace; font-size: 13.6000003814697px; padding: 0px; margin: 0px; border-radius: 3px; word-break: normal; border: 0px; display: inline; overflow: visible; line-height: inherit; word-wrap: normal; background: transparent;">    # 统计语料库中词汇在S和H中出现的次数
    wordsInSpamNum = np.ones(numWords)
    wordsInHealthNum = np.ones(numWords)
    spamWordsNum = 2.0
    healthWordsNum = 2.0
</code></pre>
<ul style="box-sizing: border-box; padding-left: 2em; margin-top: 0px; margin-bottom: 16px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">
	<li style="box-sizing: border-box;">
		计算P(Wi|S)和P(Wi|H)时，对概率取对数
	</li>
</ul>
<pre style="box-sizing: border-box; font-family: SFMono-Regular, Consolas, 'Liberation Mono', Menlo, Courier, monospace; font-size: 13.6000003814697px; margin-top: 0px; margin-bottom: 16px; font-stretch: normal; line-height: 1.45; word-wrap: normal; padding: 16px; overflow: auto; border-radius: 3px; color: rgb(36, 41, 46); background-color: rgb(246, 248, 250);"><code style="box-sizing: border-box; font-family: SFMono-Regular, Consolas, 'Liberation Mono', Menlo, Courier, monospace; font-size: 13.6000003814697px; padding: 0px; margin: 0px; border-radius: 3px; word-break: normal; border: 0px; display: inline; overflow: visible; line-height: inherit; word-wrap: normal; background: transparent;">    pWordsSpamicity = np.log(wordsInSpamNum / spamWordsNum)
    pWordsHealthy = np.log(wordsInHealthNum / healthWordsNum)
</code></pre>
<p style="box-sizing: border-box; margin-top: 0px; margin-bottom: 16px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">
	  所以最终比较的是，P(W1|S)P(W2|S)....P(Wn|S)P(S)和P(W1|H)P(W2|H)....P(Wn|H)P(H)的大小。
</p>
<pre style="box-sizing: border-box; font-family: SFMono-Regular, Consolas, 'Liberation Mono', Menlo, Courier, monospace; font-size: 13.6000003814697px; margin-top: 0px; margin-bottom: 16px; font-stretch: normal; line-height: 1.45; word-wrap: normal; padding: 16px; overflow: auto; border-radius: 3px; color: rgb(36, 41, 46); background-color: rgb(246, 248, 250);"><code style="box-sizing: border-box; font-family: SFMono-Regular, Consolas, 'Liberation Mono', Menlo, Courier, monospace; font-size: 13.6000003814697px; padding: 0px; margin: 0px; border-radius: 3px; word-break: normal; border: 0px; display: inline; overflow: visible; line-height: inherit; word-wrap: normal; background: transparent;">    ps = sum(testWordsMarkedArray * pWordsSpamicity) + np.log(pSpam)
    ph = sum(testWordsMarkedArray * pWordsHealthy) + np.log(1 - pSpam)
</code></pre>
<p style="box-sizing: border-box; margin-top: 0px; margin-bottom: 16px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">  
	<span style="box-sizing: border-box; font-weight: 600;">测试效果：</span>&nbsp;5574个样本，采用交叉验证，随机选取4574个作为训练样本，产生词汇列表（语料库），对1000个测试样本，分类的平均错误率约为：2.5%。
</p>
<h2 style="box-sizing: border-box; margin-top: 24px; margin-bottom: 16px; line-height: 1.25; padding-bottom: 0.3em; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(234, 236, 239); color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol';">
	2 Running Adaboost on Naive Bayes
</h2>
<p style="box-sizing: border-box; margin-top: 0px; margin-bottom: 16px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">
	  我们在计算ps和ph联合后验概率时，可引入一个调整因子DS，其作用是调整词汇表中某一词汇的“垃圾程度”(spamicity)，
</p>
<pre style="box-sizing: border-box; font-family: SFMono-Regular, Consolas, 'Liberation Mono', Menlo, Courier, monospace; font-size: 13.6000003814697px; margin-top: 0px; margin-bottom: 16px; font-stretch: normal; line-height: 1.45; word-wrap: normal; padding: 16px; overflow: auto; border-radius: 3px; color: rgb(36, 41, 46); background-color: rgb(246, 248, 250);"><code style="box-sizing: border-box; font-family: SFMono-Regular, Consolas, 'Liberation Mono', Menlo, Courier, monospace; font-size: 13.6000003814697px; padding: 0px; margin: 0px; border-radius: 3px; word-break: normal; border: 0px; display: inline; overflow: visible; line-height: inherit; word-wrap: normal; background: transparent;">    ps = sum(testWordsMarkedArray * pWordsSpamicity * DS) + np.log(pSpam)
</code></pre>
<p style="box-sizing: border-box; margin-top: 0px; margin-bottom: 16px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">
	  其中DS通过Adaboost算法迭代获取最佳值。原理如下：
</p>
<pre style="box-sizing: border-box; font-family: SFMono-Regular, Consolas, 'Liberation Mono', Menlo, Courier, monospace; font-size: 13.6000003814697px; margin-top: 0px; margin-bottom: 16px; font-stretch: normal; line-height: 1.45; word-wrap: normal; padding: 16px; overflow: auto; border-radius: 3px; color: rgb(36, 41, 46); background-color: rgb(246, 248, 250);"><code style="box-sizing: border-box; font-family: SFMono-Regular, Consolas, 'Liberation Mono', Menlo, Courier, monospace; font-size: 13.6000003814697px; padding: 0px; margin: 0px; border-radius: 3px; word-break: normal; border: 0px; display: inline; overflow: visible; line-height: inherit; word-wrap: normal; background: transparent;">设定adaboost循环的次数count
交叉验证随机选择1000个样本
DS初始化为和词汇列表大小相等的全一向量
迭代循环count次：
    设定最小分类错误率为inf
    对于每一个样本：
        在当前DS下对样本分类
        如果分类出错：
            计算出错的程度，即比较ps和ph的相差alpha
            如果样本原本是spam，错分成ham：
                DS[样本包含的词汇] = np.abs(DS[样本包含的词汇] - np.exp(alpha) / DS[样本包含的词汇])
            如果样本原本是ham，错分成spam：
                DS[样本包含的词汇] = DS[样本包含的词汇] + np.exp(alpha) / DS[样本包含的词汇]
    计算错误率
    保存最小的错误率和此时的词汇列表、P(Wi|S)和P(Wi|H)、DS等信息，即保存训练好的最佳模型的信息
</code></pre>
<p style="box-sizing: border-box; margin-top: 0px; margin-bottom: 16px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">  
	<span style="box-sizing: border-box; font-weight: 600;">测试效果：</span>&nbsp;5574个样本，获取Adaboost算法训练的最佳模型信息（包括词汇列表、P(Wi|S)和P(Wi|H)、DS等），对1000个测试样本，分类的平均错误率约为：0.5%。
</p>
<h2 style="box-sizing: border-box; margin-top: 24px; margin-bottom: 16px; line-height: 1.25; padding-bottom: 0.3em; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(234, 236, 239); color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol';">
	<a id="user-content-references" class="anchor" href="https://github.com/SunnyMarkLiu/NaiveBayesSpamFilter/blob/master/README.md#references" aria-hidden="true" style="box-sizing: border-box; color: rgb(3, 102, 214); text-decoration: none; float: left; padding-right: 4px; margin-left: -20px; line-height: 1; background-color: transparent;"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewbox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>References
</h2>
<p style="box-sizing: border-box; margin-top: 0px; margin-bottom: 16px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px;">
	<a href="http://web.cecs.pdx.edu/~mm/MachineLearningWinter2010/BoostingNaiveBayes.pdf" style="box-sizing: border-box; color: rgb(3, 102, 214); text-decoration: none; background-color: transparent;">Running Adaboost on Naive Bayes</a><br style="box-sizing: border-box;" />
	<a href="http://pages.cs.wisc.edu/~dyer/cs540/handouts/elkan97boosting.pdf" style="box-sizing: border-box; color: rgb(3, 102, 214); text-decoration: none; background-color: transparent;">Boosting and naive bayesian learning</a><br style="box-sizing: border-box;" />
	<a href="https://en.wikipedia.org/wiki/Naive_Bayes_spam_filtering" style="box-sizing: border-box; color: rgb(3, 102, 214); text-decoration: none; background-color: transparent;">Naive Bayes spam filtering</a><br style="box-sizing: border-box;" />
	
</p>
<h2 style="box-sizing: border-box; margin-top: 24px; margin-bottom: 16px; line-height: 1.25; padding-bottom: 0.3em; border-bottom-width: 1px; border-bottom-style: solid; border-bottom-color: rgb(234, 236, 239); color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol';">
	<a id="user-content-license" class="anchor" href="https://github.com/SunnyMarkLiu/NaiveBayesSpamFilter/blob/master/README.md#license" aria-hidden="true" style="box-sizing: border-box; color: rgb(3, 102, 214); text-decoration: none; float: left; padding-right: 4px; margin-left: -20px; line-height: 1; background-color: transparent;"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewbox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>License
</h2>
<p style="box-sizing: border-box; margin-top: 0px; color: rgb(36, 41, 46); font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'; font-size: 16px; line-height: 24px; margin-bottom: 0px !important;">
	This project is licensed under the terms of the MIT license.
</p>
<br />
