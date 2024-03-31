def get_interest_suggestions(user_id: int, include_current_interests: bool = False):

    # Create a dictionary to store similar interest suggestions
    suggestions = defaultdict(float)

    # Iterate through the user's interests
    user_interests = user_interest_vectors[user_id]
    for interest_id, is_interesting in enumerate(user_interests):
        if is_interesting == 1:
            # Find similar interests for each interest
            similar_interests = most_similar_interests_to(interest_id)
            # Add similar interests to suggestions
            for interest, similarity in similar_interests:
                suggestions[interest] += similarity

    # Sort suggestions by weight
    suggestions = sorted(suggestions.items(), key=lambda pair: pair[-1], reverse=True)

    if include_current_interests:
        return suggestions
    else:
        # Exclude current interests if specified
        return [(suggestion, weight) for suggestion, weight in suggestions
                if suggestion not in user_interests[user_id]]
