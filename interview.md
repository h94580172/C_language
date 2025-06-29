# Interview

## 1. 自我介紹

主管們好，我叫賴英傑，我畢業於虎尾科技大學光電所，並有3年韌體客製化經驗，主要以寫C為主。而在目前的工作上我負責提供客戶客製化的FW(當我收到開案單時，先確認需求，確認完後再依照需求去開發FW並驗證)及解決相容性問題(客戶若驗證產品上有測試到相容性問題，會蒐集一下問題並透過儀器去分析解決問題)

## 2. 個人優點？

對工作負責：若專案很緊急需要加班也願意去做。
學習能力快：能快速適應新環境，學習新技能或工具。
團隊合作：善於與同事協作，促進團隊目標達成。

## 3. 個人缺點？

細節處理：有時因想提升效率而忽略細節，現在學習平衡工作效率與細節處理。
工作處理：有時因有數個工作需處理進而忘記安排工作順序，現在學習依照事情緊急程度依序處理。

## 4. 你曾經面臨過什麼挑戰，如何克服？

1.之前在做投影機的時候，曾經有遇到投影機他接著我們要投影的裝置然後關機再開機，但這時候會有相容性的問題導致不能充電及出畫面，後來透過式波器及PD的分析儀器才發現說，關機的時候在type-c上的VBUS電壓沒有被放掉，所以導致關機後馬上開機的時候我們那時候會自行檢查VBUS是否 < Vsafe0V，但那時候沒有所以會導致我們的PD flow有問題，進而造成相容性問題，而後面發現這問題後就有請投影機裡面負責MCU的廠商協助通知我們投影機關機，我們在去進行放電動作。

vSafe0V 的定義：
根據 USB Type-C 規範，vSafe0V 是指 VBUS 電壓在無有效連接時應低於 0.8V，表示電源提供端（Source）未主動供電。
這是確保新連接時，系統能從「乾淨」的電壓狀態開始，進行角色偵測（Source 或 Sink）。
當設備斷開或未檢測到有效連接時，VBUS 必須回到 vSafe0V，以確保安全且避免損壞設備或引起誤操作。

2.一樣是投影機，有遇過接上某個裝置的時候，會發現我們FW重新跑了，代表IC電有被斷掉過，但這個是隨機性的，一開始確認我們控制Mos開關的GPIO是否有錯，確認PDO報的數值等等，都沒發現異常，後來在PD分析儀上看到VBUS_current好像有一條異常的突波，而那突波剛好觸發到我們OCP的設定，所以才會導致我們pmic把電整個關掉，後續發現這問題後，發現好像只有這台裝置有這問題，跟客戶討論後就先略過這台。

## 5. 你在過去的工作中最大的成就是什麼？

之前公司剛要開始做新的應用，是要做投影機，而我是負責這塊新應用的人，所以從一開始跟投影機廠商溝通相關技術需求，及後續FW要如何設計，是要用哪顆pmic，設計ocp的規格等等..，或是相關PD的PDO設定等等，GPIO/影像設定等等。

## 6. 描述一次你與團隊意見不合的情況，你如何處理？

若遇到意見不合的情況時，通常我會先聆聽團隊其他人的意見後，思考一下自己的意見跟大家不同的點是什麼，並把自己的觀點與其他團隊成員溝通，然後再討論出一個大家都能認同的方式。

## 7. 如果你在期限內無法完成任務，你會怎麼做？

我會想看有沒有任何方法能夠盡量在時間內把任務完成，想好可以如何做後我會找主管，並把想到的作法跟主管討論並努力在時間內完成任務。

## 8. 你對我們公司了解多少？

瑞昱 : 網通晶片產品(WiFi、乙太、WLAN、Switch、藍牙)，其他產品線包含PC週邊相關(Audio Codec、IPCam、讀卡機、SSD控制、USB Type-C)及多媒體應用(TV SOC、LCD控制)

創惟 : PD/HUB controller / Card Reader / Repeater / Mux

新唐 : 新唐是台灣前幾大的MCU IC design house，做的應用有伺服器BMC或是電腦Embedded Controller / 工業及汽車(BMIC) / 消費性產品(家電類) / 醫療照顧(血糖儀)。

新唐科技EC應用的概述
定義：嵌入式控制器（EC）是一種內建於系統中的微控制器，負責管理一些硬體功能，像像鍵盤控制、電源管理、電池監控、風扇控制等等。

印能 : 是國內第一家提供並導入量產以高壓高溫烤箱解決封裝製程中的問題，解決的問題主要有先進封裝產生的氣泡、翹曲等等，還提供自動化系統解決方案。

## 9. 你為什麼想加入我們公司？

瑞昱、創惟 : 會想加入瑞昱、創惟，除了可以跟很多厲害的人交流外，也能學習更多不同的技術與知識，我也能把自己所學的技術能力應用在工作上，跟著公司一同成長。

新唐 : 因為新唐其實在MCU業界中算很有名，而我覺得加入新唐後，除了可以跟很多厲害的人交流外，也能學習更多不同的技術與知識，我也能把自己所學的技術能力應用在工作上，跟著公司一同成長。

印能 : 因為印能是國內第一家提供並導入量產以高壓高溫烤箱解決封裝製程中的問題，除了在產業地位上是很強的外，我也沒有在半導體設備廠工作過，其實對於這塊蠻有興趣的。

## 10. 為何要離職？  

主要是因為公司現在正在轉型，但我覺得公司的轉型跟我當初想進來安格學習的東西都不同了，漸漸的我也找不到我當初在這份工作上工作的那份熱忱。

## 11. 講述一次你犯錯的經驗，你從中學到了什麼？
  
這發生在我剛開始工作沒多久的時候，那時候因為工作負責的內容是出客製化的FW給大陸的白牌客戶，但大陸白牌客戶其實需求都很類似，所以在某一次要給FW之前，我沒有仔細驗證FW就給出去了，而後續舊客戶有反應FW有問題，後面查了才發現 哦...原來是改code的時候有個地方沒改到，所以FW動作才會不如客戶預期，經由這件事後，只要FW有任何改動我都一定會驗證確認這個FW沒問題我才會給到客戶。

## 12. 你未來 3-5 年的職業目標是什麼？

短期:先熟悉工作範圍內的所有內的所有工作項目，讓自己能獨立完成專案任務。
長期:把工作上所學的東西更加精進，讓自己在工作上的專業能力可以越來越好。

## 13. 如果一直達不到工作目標時，你會怎麼辦？

先看工作目標是否對於當下的我來說有執行上的困難，若有的話則會找主管討論一下我現在遇到的狀況，然後自己也要想是否有方式能改善現在的狀況，讓自己達成目標，例如多花一些時間去往目標的事情努力。

## 14. 為何要錄取你?

除了我原本就有替客戶寫客製化FW的經驗能夠快速上手外，若在工作能力上有任何不足的地方我也願意花時間去學習。
  
## 15. 你有什麼問題想問我們？

1. 這個職位的日常工作內容和主要挑戰是什麼？

2. 您能分享一下團隊目前的規模和結構嗎？

3. 您認為行業目前的趨勢對貴公司有什麼影響？

4. 公司福利

5. 是否調薪

6. 機車汽車停車