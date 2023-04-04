import requests
import sys

URL = "https://pokeapi.co/api/v2/pokemon/{pokemon_name}"

if __name__ == "__main__":
    pokename = input("Enter the name of a Pokemon: ").lower()
    try:
        response = requests.get(URL.format(pokemon_name=pokename))
        if response.status_code != 200:
            print("Sorry, I couldn't find that Pokemon.")
            sys.exit(1)
        data = response.json()
        print("Name: {}".format(data["name"].title()))
        print("Abilities:")
        for ability in data["abilities"]:
            print("- {}".format(ability["ability"]["name"].title()))
    except requests.exceptions.RequestException as e:
        print("Request failed!")
