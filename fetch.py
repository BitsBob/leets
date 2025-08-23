import requests
import sys

HEADERS = "#include <bits/stdc++.h>\nusing namespace std;\n\n"

def get_slug_from_number(problem_number: int) -> str:
    url = "https://leetcode.com/api/problems/all/"
    resp = requests.get(url)
    resp.raise_for_status()
    data = resp.json()

    for q in data["stat_status_pairs"]:
        if q["stat"]["frontend_question_id"] == problem_number:
            return q["stat"]["question__title_slug"]
    return None

def get_cpp_code(slug: str) -> str:
    url = "https://leetcode.com/graphql"
    query = {
        "query": """
        query getQuestion($titleSlug: String!) {
          question(titleSlug: $titleSlug) {
            codeSnippets {
              langSlug
              code
            }
          }
        }
        """,
        "variables": {"titleSlug": slug},
    }
    resp = requests.post(url, json=query)
    resp.raise_for_status()
    data = resp.json()

    for snippet in data["data"]["question"]["codeSnippets"]:
        if snippet["langSlug"] == "cpp":
            return snippet["code"]
    return None

def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <problem_number>")
        sys.exit(1)

    problem_number = int(sys.argv[1])

    slug = get_slug_from_number(problem_number)
    if not slug:
        print("Problem not found")
        sys.exit(1)

    cpp_code = get_cpp_code(slug)
    if not cpp_code:
        print("C++ template not available")
        sys.exit(1)

    filename = f"{problem_number}.cpp"
    with open(filename, "w") as f:
        f.write(HEADERS + cpp_code)

    print(f"Generated {filename} with standard headers")

if __name__ == "__main__":
    main()

