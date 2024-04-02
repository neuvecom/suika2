Suika2
======

<!-- ## What is Suika2? -->
## Suika2とは？

<!-- Suika2 is a development suite for Visual Novels.
It has an open-source philosophy and is designed with a true cross-platform portablity including iOS and Android.
It is equipped with features and tools of production-grade quality.
Suika2 is perfect for both beginners and seasoned creators alike. -->
Suika2はビジュアルノベルのための開発スイートです。
オープンソースの理念を持ち、iOSとAndroidを含む真のクロスプラットフォーム移植性を持って設計されています。
プロダクショングレードのクオリティの機能とツールを備えています。
Suika2は、初心者からベテランのクリエイターまで幅広くお使いいただけます。

<!-- Effortlessness and efficiently are key concepts of Suika2.
It provides that without sacrificing features or usability to enrich both the creator and user experience. -->
Suika2のキーコンセプトは「手間いらず」と「効率的」。
機能や使い勝手を犠牲にすることなく、作り手と使い手の双方を豊かにします。

<!-- We don't aim for no-code but we achieve low-code using multiple DSLs, Domain Specific Languages.
Specifically, there are separate languages for scenarios, GUI, and logic.
We are in the process of adding a little graphical support for each DSL.
This is quite different from other engines and we call it "Visual Live Scripting" technology.
The author thinks as a researcher of software engineering that VLS is one shape of RAD, Rapid Application Development. -->
私たちはノーコードを目指しているわけではありませんが、複数のDSL（ドメイン固有言語）を使ってローコードを実現しています。
具体的には、シナリオ、GUI、ロジックの各言語があります。
現在、各DSLにちょっとしたグラフィカル・サポートを追加しているところです。
これは他のエンジンとは全く異なるもので、私たちはこれを「ビジュアル・ライブ・スクリプト」技術と呼んでいます。
筆者はソフトウェア工学の研究者として、VLSはRAD（Rapid Application Development）の一つの形であると考えている。

<!-- ## What is the Suika2's Development Goal? -->
## Suika2の開発目標は？

<!-- **"The New Standard for Visual Novel Creation"**, in the era of 2020s and beyond, is the goal of the Suika2 development. -->
**2020年代、そしてその先の時代の「ビジュアルノベル制作の新しいスタンダード」**、それがSuika2の開発目標です。

<!-- ## What are the Suika2's Mission, Vision and Values (MVV)? -->
## Suika2のミッション、ビジョン、バリュー（MVV）は何ですか？

<!-- * Mission
  * **Simple:** Suika2 enables the creation of Visual Novels in an easy and efficient manner.
  * **Fast:** Apps are constructed using native technologies only, ensuring resource efficiency on mobile devices.
  * **Free:** We are an open source project and we make our technology public as pro-bono-publico with respects for intellectual properties of others. -->
- ミッション
  - **シンプル：** Suika2は、簡単かつ効率的な方法でビジュアルノベルの作成を可能にします。
  - **高速：** アプリはネイティブ技術のみで構築され、モバイルデバイスでのリソース効率を保証します。
  - **自由：** 私たちはオープンソースプロジェクトであり、他者の知的財産を尊重したプロボノパブリコとして技術を公開しています。
<!-- - Vision
  - **Earning:** Game developers can publish their games on stores and earn income.
  - **Prosperity:** Our aim is to create a world where anyone can make a living with just a single computer including mobile devices.
  - **Talent**: Bringing people with talents but difficulties into the world (Giftedness support) -->
- ビジョン
  - **収益：** ゲーム開発者は、自分のゲームをストアで公開し、収入を得ることができます。
  - **繁栄：** 私たちの目標は、誰もがモバイルデバイスを含むコンピュータ1台で生計を立てられる世界を作ることです。
  - **才能：** 才能がありながら困難を抱えている人たちを世に送り出す（才能支援）
<!-- - Values
  - **Information:** We hold the belief that the creation and generation of information including story writing is humanity's true value.
  - **Market:** We shall complete the market launch of game subscriptions with world leading platform partners.
  - **Diversity:** Develop, distribute, and publish on all platforms - Suika2 seeks the true portability and we call it diversity. -->
- 価値観
  - **情報：** ストーリーライティングを含む情報の創造と生成こそが人類の真の価値であるとの信念を持つ。
  - **市場：** 私たちは、世界をリードするプラットフォームパートナーと共に、ゲーム配信の市場投入を完了します。
  - **多様性：** Suika2は真のポータビリティを追求し、それを多様性と呼びます。

<!-- ## Downloads -->
## ダウンロード

<!-- Note that releases on stores are older than the latest version on GitHub and the Web site because stores take 2-3 business days for reviews but we do 2-3 releases a day.
Please visit [the official Web site](https://suika2.com/en/dl/) to obtain the latest release. -->
注：ストアのリリースはGithubやウェブサイトの最新版より古いことに注意してください。ストアはレビューに2-3営業日かかりますが、私たちは1日に2-3リリースしているからです。
最新のリリースを入手するには、[公式ウェブサイト](https://suika2.com/en/dl/)をご覧ください。

* On Windows (Suika2 Pro Desktop):
  * Open [Microsoft Store](https://apps.microsoft.com/detail/XP99CQV05PR79W)

* On Mac (Suika2 Pro Desktop):
  * Open [Mac App Store](https://apps.apple.com/us/app/suika2-pro-desktop/id6474658254)

* On iPhone/iPad (Suika2 Pro Mobile):
  * Open [App Store](https://apps.apple.com/us/app/suika2-pro-mobile/id6474521680)

* On Android/Chromebook (Suika2 Pro Mobile):
  * Open [Google Play](https://play.google.com/store/apps/details?id=jp.luxion.suikapro)

* On Linux including terminal of Chromebook (Suika2 Pro Desktop):
  * You can build from the souce code:
  ```
  sudo apt-get install -y git build-essential libasound2-dev libx11-dev mesa-common-dev qt6-base-dev qt6-multimedia-dev libwebp-dev
  git clone https://github.com/suika2engine/suika2.git
  ./configure
  make
  sudo make install
  suika2
  ```
  * Or you can use the `apt` command on Ubuntu:
  ```
  sudo add-apt-repository ppa:ktabata/ppa
  sudo apt update
  sudo apt install suika2
  suika2
  ```

## Discord

Our community is a cherished and invaluable space that embraces developers, creators, and end-users irrespective of their nationality, language, ethnicity, color, lineage, beliefs, sexuality, gender, education, age, religion, or identity.
That's why we'd love you to join our community!
You're definitely deserved to be a part of it.

<a href="https://discord.gg/EzCxCh3f">

We hold a grand vision for cultural growth and engage in profound discussions, but at our core, we are simply developers and creators, so we are always interested in dialogue and conversation!

## Suika2 Pro series

`Suika2 Pro Desktop` and `Suika2 Pro Mobile` are Suika2's creator tools, available for Windows PC, Mac, iPhone, iPad, Android phone/tablet, Chromebook and Linux.
They provide creators with all the functionalities they need, such as editing, debugging, and exporting games out of the box.

## License

This software is released under the MIT license.
There is no restriction on distribution and or modification of the Suika2 Source Code.

This project will never be commercialized in the future. Please use Suika2 with confidence.

## Contribution

The best way to contribute to this project is to use it and give us feedback.
We are always open to suggestions and ideas.

## Live Web Demo

<a href="https://suika2.com/run/sample/"><img src="https://github.com/suika2engine/suika2/raw/master/.doc/screenshot.jpg"></a>

## Documentation

* [Japanese Documentation](https://suika2.com/wiki/?%E3%83%89%E3%82%AD%E3%83%A5%E3%83%A1%E3%83%B3%E3%83%88)
* [English Documentation](https://suika2.com/en/doc/)

## Portability

Games made with Suika2 can run on Windows PC, Mac, iPhone, iPad, Android, Web browser, Chromebook, Linux, FreeBSD, NetBSD, OpenBSD, and some commercial consoles.

Suika2 consists of the platform independent core (CORE) and the hardware abstraction layer (HAL).
The CORE is written in ANSI C, the most portable programming language in the world, while HAL implementations are currently written in C, C++, Objective-C, Swift and Java.

If you would like to port Suika2 to a new target platform, you only need to write a thin HAL, this is generally possible within a week.

Suika2 does not depend on SDKs or frameworks such as Unity, Godot, Python, or SDL2, this is thanks to the extensive design of HAL, our compatibility layer's API.

## CI/CD Pipiline

* We do CI for build sanity checks on every push to the repository using GitHub Actions.
* We currently don't have a way to do CD on the cloud due to a lack of code signing capability.
* However, the author has a release script and thus releases are fully automated on his MacBook Pro.
  * The release script builds all binaries and uploads them to the Web site and GitHub.
  * It also posts a message to the Discord server.
  * This is generally done in 10 minutes.

## Trivia

Did you know that...

* Midori wears a watermelon themed tie and pair of hair ribbons to stand out in her uniform?
* "Suika" means "watermelon" in Japanese?
* Suika2 is the successor to "Suika Studio" and the author is a pioneer in the field of GUI editors for visual novel creation?
  * [See the 2002 version here](https://github.com/ktabata/suika-studio-2002-gpl)
  * [See the 2003 version here](https://github.com/ktabata/suika-studio-2003-gpl)

## Sponsors

[Here's where you raise your banner!](https://github.com/ktabata/suika2/raw/master/FUND.md)

**Come forward**, those who resonate with our vision and are of like mind.

VENITE ET VIDEBITIS
