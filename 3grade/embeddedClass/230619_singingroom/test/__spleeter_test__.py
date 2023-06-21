import os
from spleeter.separator import Separator

# 2stems = vocals and accompaniment
# 4stems = vocals, drums, bass, and other
# 5stems = vocals, drums, bass, piano, and other
file_name = str(input('음악 파일의 dir 적어주세요. >>>'))
output_dir = 'output'

separator = Separator('spleeter:2stems')
separator.separate_to_file(file_name, output_dir)
print('END')
