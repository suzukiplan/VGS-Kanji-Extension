# VGS-Kanji-Extension
- VGSの拡張漢字ROMをVGSアプリに組み込むことで、日本語を表示することができます。
- VGSでRPG、物語性のあるSLG、ノベルゲームなどを開発する時にご活用ください。
- GameDaddyでも使用することができます。

# 使い方
1. GSLOT255.CHRをVGSアプリに組み込む（GameDaddy の場合は GSLOT255_GD.CHR から _GD を外したものを組み込む）
2. DSLOT255.DATをVGSアプリに組み込む
3. game.cのvge_init関数の定義内容を元にDSLOT255をロードする処理を実装する
4. game.cに定義されているgetcode関数およびputkanji関数を自分のアプリのgame.cに張り付ける

（補足）
- 上記の手順を踏めば、putkanji関数で日本語フォントを表示できます。
- 初期VGS、GameDaddyの両方で同じ手順で使えます（GameDaddyの場合はputkanjiの引数colに7を指定）
- putkanji関数の引数textには、SJISので、JIS X 0201の7bit ASCII 及び JIS X 0208の日本語を指定できます。
- ソースコード上にハードコーディングする場合、エンコードをSJISにする必要があります。
- 最近の（主に海外製の）IDEはSJISに対応していなかったりするので、通常はハードコーディングせず、本サンプルのようにDATA SLOT上にバイナリデータとして定義することを推奨します。

# DSLOT255.DAT (KANJI.ROM)
k8x12S（2015年1月31日時点のもの）に含まれる日本語（JIS X 0208）のフォントデータを独自形式に変換したものです。

（データ構成仕様）
- JIS X 0208の全ての文字画像データが格納されています
- JIS X 0208の区画毎のバウンダリ領域は含みません
- 1文字あたり12バイトです（全8,836文字）
- 12バイト = 横8ピクセルを1バイト × 縦12ピクセル

# ライセンス
## GSLOT255.CHR
GSLOT255.CHRは、門真 なむ様の8×12 ドット日本語フォント「k8x12」のk8x12S（2015年1月31日時点のもの）に含まれる7bit ASCII（JIS X 0201の内0x20～0x7Fの範囲）のフォントデータをvgsbmpコマンドで変換したものです。

## DSLOT255.DAT
DSLOT255.DATは、門真 なむ様の8×12 ドット日本語フォント「k8x12」のk8x12S（2015年1月31日時点のもの）に含まれる日本語（JIS X 0208）のフォントデータを独自形式に変換したものです。
- http://www.geocities.jp/littlimi/index.html
- http://www.geocities.jp/littlimi/k8x12.htm

## GSLOT255.CHR 及び DSLOT255.DAT のライセンス
GSLOT255.CHR 及び DSLOT255.DAT のライセンスについては、http://www.geocities.jp/littlimi/font.htm#license に記載されているライセンス条項に基づいて使用できます。
2015年1月31日時点の記載内容を以下に引用します。
> - These fonts are free software.
> - Unlimited permission is granted to use, copy, and distribute them, with or without modification, either commercially or noncommercially.
> - THESE FONTS ARE PROVIDED "AS IS" WITHOUT WARRANTY.
> - これらのフォントはフリー（自由な）ソフトウエアです。
> - あらゆる改変の有無に関わらず、また商業的な利用であっても、自由にご利用、複製、再配布することができますが、全て無保証とさせていただきます。

## GSLOT255.CHR 及び DSLOT255.DAT 以外のライセンス
GSLOT255.CHR 及び DSLOT255.DAT を除くデータ及びソースコードの著作権は、SUZUKI PLANが有します。
本リポジトリ掲載のSUZUKI PLANの著作物は、VGSの使用許諾と同等の条件でご利用いただけます。
