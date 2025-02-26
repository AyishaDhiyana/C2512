import json

with open("data.json") as file:
    user_data = json.load(file)

Category_mr = {}
Category_mrs = {}

for datas in user_data:
    if isinstance(datas, list):
        for key, value in datas.items():
            if isinstance(value, dict):
                for info in infos:
                    if isinstance(info, dict):
                        user_info = {
                            "name" : info.get("name"),
                            "age" : info.get("age"),
                            "phone" : info.get("phone")
                        }

                        if info.get("title") == "Mr.":
                            Category_mr.append(user_info)
                        if info.get("title") == "Mrs.":
                            Category_mrs.append(user_info)

with open("Category_Mr.json", "w") as Category_1:
    json.dump(Category_mr, Category_1, indent = 4)
    
with open("Category_Mrs.json", "w") as Category_2:
    json.dump(Category_mrs, Category_2, indent = 4)

print("JSON files created successfully!!")
