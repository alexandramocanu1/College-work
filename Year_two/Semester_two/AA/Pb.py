import random
import numpy as np

def fitness(x, a, b, c):
    return -a * x ** 2 + b * x + c

def init_population(pop_size, domain, precision):
    return [decimal_to_binary(random.uniform(domain[0], domain[1]), precision) for _ in range(pop_size)]

def evaluate_population(population, a, b, c, domain):
    return [fitness(binary_to_decimal(chromosome, domain), a, b, c) for chromosome in population]

def selection(population, fitness_values):
    total_fitness = sum(fitness_values)
    probabilities = [fit / total_fitness for fit in fitness_values]
    cumulative_probs = np.cumsum(probabilities)
    selected = []

    for _ in range(len(population)):
        rand_val = random.random()
        index = binary_search(cumulative_probs, rand_val)
        selected.append(population[index])
    return selected

def binary_search(arr, val):
    low, high = 0, len(arr) - 1
    while low < high:
        mid = (low + high) // 2
        if arr[mid] < val:
            low = mid + 1
        else:
            high = mid
    return low

def crossover(parent1, parent2, crossover_prob):
    if random.random() < crossover_prob:
        crossover_point = random.randint(1, len(parent1) - 1)
        child1 = parent1[:crossover_point] + parent2[crossover_point:]
        child2 = parent2[:crossover_point] + parent1[crossover_point:]
        return child1, child2
    else:
        return parent1, parent2

def mutation(chromosome, mutation_prob):
    mutated_chromosome = ''
    for bit in chromosome:
        if random.random() < mutation_prob:
            mutated_chromosome += '1' if bit == '0' else '0'
        else:
            mutated_chromosome += bit
    return mutated_chromosome

def decimal_to_binary(number, precision):
    scaled_number = int(number * (10 ** precision))
    binary_string = format(scaled_number, '0' + str(precision) + 'b')
    return binary_string

def binary_to_decimal(binary_string, domain):
    scaled_number = int(binary_string, 2)
    return scaled_number / (10 ** len(binary_string)) * (domain[1] - domain[0]) + domain[0]

def read_input(filename):
    with open(filename, 'r') as file:
        lines = [line.strip() for line in file.readlines() if not line.startswith('#')]

        pop_size = int(lines[0])
        domain = [float(val) for val in lines[1].split()]
        a, b, c = [float(val) for val in lines[2].split()]
        precision = int(lines[3])
        crossover_prob = float(lines[4])
        mutation_prob = float(lines[5])
        generations = int(lines[6])

        return pop_size, domain, a, b, c, precision, crossover_prob, mutation_prob, generations

def genetic_algorithm(pop_size, domain, a, b, c, precision, crossover_prob, mutation_prob, generations):
    population = init_population(pop_size, domain, precision)
    best_individual = None

    with open("Evolutie.txt", "w") as file:
        file.write("Populatia initiala\n")
        for i, chrom in enumerate(population):
            x_val = binary_to_decimal(chrom, domain)
            print(f"{i + 1}:  x= {x_val:.4f} f={fitness(x_val, a, b, c):.4f}", file=file)

        for gen in range(generations):
            fitness_values = evaluate_population(population, a, b, c, domain)
            max_fitness = max(fitness_values)
            mean_fitness = np.mean(fitness_values)

            selected_population = selection(population, fitness_values)

            offspring = []
            for i in range(0, pop_size, 2):
                child1, child2 = crossover(selected_population[i], selected_population[i + 1], crossover_prob)
                offspring.extend([child1, child2])

            mutated_offspring = [mutation(chrom, mutation_prob) for chrom in offspring]

            elite = max(mutated_offspring, key=lambda x: fitness(binary_to_decimal(x, domain), a, b, c))
            mutated_offspring.append(elite)

            population = mutated_offspring

            best_fitness = max(fitness_values)
            if best_individual is None or best_fitness > fitness(binary_to_decimal(best_individual, domain), a, b, c):
                best_individual = max(population, key=lambda x: fitness(binary_to_decimal(x, domain), a, b, c))

            print(f"\nGeneratia {gen + 1}:", file=file)
            print(f"Cel mai bun individ: {best_individual} cu fitness: {best_fitness:.4f}", file=file)
            print(f"Media fitness-ului: {mean_fitness:.4f}", file=file)

    return binary_to_decimal(best_individual, domain), max_fitness

if __name__ == "__main__":
    pop_size, domain, a, b, c, precision, crossover_prob, mutation_prob, generations = read_input("input.txt")
    best_x, best_fitness = genetic_algorithm(pop_size, domain, a, b, c, precision, crossover_prob, mutation_prob, generations)
    print(f"\nCel mai bun x: {best_x}, fitness: {best_fitness}")
