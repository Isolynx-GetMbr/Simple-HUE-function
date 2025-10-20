<!-- crazy shit oat. -->

# Simple HUE function (2022)
> [Old repo (main)](https://github.com/GetMbr/My-first-HSL-code-C-/tree/main)

Actually wrote this based on my outcome that came to my mind back in 2022, a little bit of tweaks and trial and error, </br>
but still managed it to work anyways. Somehow a little mistake here, as it would reset all the RGB variables           </br>
back to zero when blue reaches 255.                                                                                    </br>

### UPDATE (as of 2025年10月20日)
The new hue code can finally shift without resetting to zero when the blue reaches 255, thanks to phases, which I later  </br>
find out about it, and also modern features like lambdas which can make the code much shorter and easier while classes   </br>
can make it run on multiple instances without the values getting mixed up when it got executed simutaneously between     </br>
different threads using the same function.                                                                               </br>
</br></br>
# シンプルなHUE関数 (2022年)
> [旧リポジトリ (main)](https://github.com/GetMbr/My-first-HSL-code-C-/tree/main)

実は2022年に思い浮かんだ結果を基に書いたもので、少し調整と試行錯誤を重ねたが、                               </br>
それでも何とか動作させた。ここで少しミスがあって、青が255に達するとすべてのRGB変数がゼロにリセットされてしまう。</br>

### 更新 (2025年10月20日時点)
ブルーが255に達してもゼロにリセットされずに色相コードをシフトできるようになった。                       </br>
これはフェーズ（後で知った概念）と、コードを大幅に簡潔化できるラムダ式といった現代的な機能のおかげだ。    </br>
クラスを使えば、同じ関数を異なるスレッドで同時に実行しても値が混ざることなく複数インスタンスで動作する。  </br>                                                                            

