import os
import re
import shutil

def classify_files(directory):
    # 定义匹配文件名的正则表达式
    pattern = re.compile(r'^ABC\d+[A-Z]')
    # 遍历给定目录下的所有文件
    for filename in os.listdir(directory):
        filepath = os.path.join(directory, filename)
        # 如果是文件并且文件名匹配给定模式
        if os.path.isfile(filepath) and pattern.match(filename):
            # 提取文件名中的字母部分
            
            letter = ""
            cnt = 0
            for char in filename:
                if char >= 'A' and char <= 'Z':
                    cnt += 1
                    if cnt == 4 : break
                letter += char
            # 创建目标文件夹（如果不存在）
            target_folder = os.path.join(directory, letter)
            # print(filename)
            # print(target_folder)
            if not os.path.exists(target_folder):
                os.makedirs(target_folder)
            
            # 构造目标路径并移动文件
            target_path = os.path.join(target_folder, filename)
            shutil.move(filepath, target_path)
            print(f"Moved: {filename} -> {target_folder}")

# 使用函数，传入包含待分类文件的目录路径
classify_files('./')