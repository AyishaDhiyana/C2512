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
=========================================

[
    {
        "name": "Ike Pagac",
        "info": {
            "title": "Ms.",
            "age": 48,
            "phone": "418.287.8284",
            "email": "uflatley@yahoo.com"
        }
    },
    {
        "name": "Jacynthe Nitzsche",
        "info": {
            "title": "Mr.",
            "age": 58,
            "phone": "+1-414-397-3256",
            "email": "stiedemann.sally@hotmail.com"
        }
    },
    {
        "name": "Makayla Abernathy",
        "info": {
            "title": "Miss",
            "age": 55,
            "phone": "1-767-244-0957 x995",
            "email": "hertha.moen@gmail.com"
        }
    },
    {
        "name": "Selmer Parisian",
        "info": {
            "title": "Mrs.",
            "age": 34,
            "phone": "1-295-448-0053 x4090",
            "email": "christ83@yahoo.com"
        }
    },
    {
        "name": "Teagan Glover",
        "info": {
            "title": "Miss",
            "age": 33,
            "phone": "+1-959-244-4347",
            "email": "kmorissette@gmail.com"
        }
    },
    {
        "name": "Adela Thompson",
        "info": {
            "title": "Prof.",
            "age": 20,
            "phone": "395-592-9579 x66007",
            "email": "kertzmann.monte@yahoo.com"
        }
    },
    {
        "name": "Maynard O'Keefe",
        "info": {
            "title": "Miss",
            "age": 57,
            "phone": "1-727-554-5352 x2470",
            "email": "carter.carlee@hotmail.com"
        }
    },
    {
        "name": "Turner Lehner",
        "info": {
            "title": "Mrs.",
            "age": 49,
            "phone": "(624) 701-2906 x89758",
            "email": "carley07@yahoo.com"
        }
    },
    {
        "name": "Reggie Luettgen",
        "info": {
            "title": "Mr.",
            "age": 49,
            "phone": "308.763.2032",
            "email": "pbogan@hotmail.com"
        }
    },
    {
        "name": "Serenity Legros",
        "info": {
            "title": "Mrs.",
            "age": 44,
            "phone": "1-838-782-1537 x550",
            "email": "dorothea71@yahoo.com"
        }
    },
    {
        "name": "Kayden McLaughlin",
        "info": {
            "title": "Dr.",
            "age": 54,
            "phone": "1-602-638-6701",
            "email": "paige17@gmail.com"
        }
    },
    {
        "name": "Sallie Smith",
        "info": {
            "title": "Mr.",
            "age": 54,
            "phone": "+1.880.220.3264",
            "email": "uhudson@gmail.com"
        }
    },
    {
        "name": "Angelita Haley",
        "info": {
            "title": "Prof.",
            "age": 27,
            "phone": "364-250-7327",
            "email": "johanna30@hotmail.com"
        }
    },
    {
        "name": "Blake Mitchell",
        "info": {
            "title": "Dr.",
            "age": 43,
            "phone": "+1-706-759-9161",
            "email": "beahan.nick@gmail.com"
        }
    },
    {
        "name": "Dillan Lowe",
        "info": {
            "title": "Ms.",
            "age": 20,
            "phone": "228-969-3235 x696",
            "email": "monroe.oberbrunner@hotmail.com"
        }
    },
    {
        "name": "Talia Ferry",
        "info": {
            "title": "Prof.",
            "age": 26,
            "phone": "(525) 614-6093 x539",
            "email": "parmstrong@gmail.com"
        }
    },
    {
        "name": "Candace Rosenbaum",
        "info": {
            "title": "Dr.",
            "age": 38,
            "phone": "381-396-2590 x8230",
            "email": "leatha.lebsack@hotmail.com"
        }
    },
    {
        "name": "Yvonne Kreiger",
        "info": {
            "title": "Mr.",
            "age": 49,
            "phone": "+1.725.994.3035",
            "email": "kody24@hotmail.com"
        }
    },
    {
        "name": "Kamron Dietrich",
        "info": {
            "title": "Ms.",
            "age": 55,
            "phone": "1-820-217-3574 x6751",
            "email": "willis11@hotmail.com"
        }
    },
    {
        "name": "Diego Hodkiewicz",
        "info": {
            "title": "Dr.",
            "age": 57,
            "phone": "1-717-493-6799",
            "email": "jast.henri@gmail.com"
        }
    }
]
