def interest_suggestions(user_id: int, include_current: bool = False):
    sug = defaultdict(float)
    ints = user_interest_vectors[user_id]
    
    for i, int in enumerate(ints):
        if int == 1:
            for s_int, sim in most_similar_interests_to(i):
                sug[s_int] += sim

    sug = sorted(sug.items(), key=lambda p: p[-1], reverse=True)

    return sug if include_current else [(s, w) for s, w in sug if s not in ints[user_id]]
