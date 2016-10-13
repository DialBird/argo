# あなたは、「わたしの秋は◯◯の秋」というアンケートの集計を任されました。
#
# アンケートの回答はまちまちで、「◯◯の秋」と書く人もいれば「◯◯」の部分だけ書く人もいます。これでは不便なのでまず「◯◯」の部分だけを取り出すプログラムを作りましょう。
#
# 例)
# 回答が "syokuyokunoaki" → "syokuyoku" を取り出す
# 回答が "sports" → "sports" のまま


input_lines = gets

# include?の場合
if input_lines.include?("noaki")
      input_lines.gsub!(/noaki$/, "")
end

# end_with?の場合
if input_lines.include?("noaki\n")
      input_lines.gsub!(/noaki$/, "")
end

print input_lines
