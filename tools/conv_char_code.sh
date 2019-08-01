#!/bin/sh

#テキストファイルならUTF-8/LFに置換する
ConvTextFile() {
  a=$(file --mime "$1" | grep "charset=binary")
  if [ -z "$a" ]; then
    echo $1
    nkf -w --overwrite -Lu $1
  fi
}

#変換対象のディレクトリをパラメータ指定
#指定なしなら、カレントディレクトリが対象
TOPDIR=.
if [ $# -gt 0 ]; then
  TOPDIR=$1
fi

#再帰的にサーチして変換していく
for f in `\find $TOPDIR`; do
  ConvTextFile $f
done

