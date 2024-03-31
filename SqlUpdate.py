def update(self, updates: dict, predicate: callable = lambda row: True):
    # Validate the updates
    for column, new_value in updates.items():
        if column not in self.columns:
            raise ValueError(f"Invalid column: {column}")
        if not isinstance(new_value, type(self.rows[0].__dict__[column])):
            raise TypeError(f"Expected type {type(self.rows[0].__dict__[column])}, but got {type(new_value)}")

    # Update rows based on the predicate and updates
    for row in self.rows:
        if predicate(row):
            for column, new_value in updates.items():
                row.__dict__[column] = new_value
