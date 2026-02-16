## AtCoder

ディレクトリ構成

```
contests/
	ABC/
		ABCNNN/        # A.cpp, B.cpp, ...
		setup.sh
		ac-commit.sh   # ABC用 add/commit 補助
	ARC/
		ARCNNN/
	AGC/
		AGCNNN/
	AHC/
		AHCNNN/

Typical90/
EDPC/
practice/
atcoder/           # ACL
```

ABCコミット補助

```bash
# 変更されたABCの問題ファイルを自動検出（デフォルト）
./contests/ABC/ac-commit.sh

# pushまで実行したい時だけ
./contests/ABC/ac-commit.sh --push

# 手動指定も可能
./contests/ABC/ac-commit.sh 443 A B C
```
