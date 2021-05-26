"""
press f to Fast/slow
press i to show/hide additional Info
press a to Add custom unit
press p to Pause/unpause
press n to Next step
press g to GENOCIDE (delete all dead-end)
press s to go Superfast
press r to add Random cells
"""

import pygame
import random
import math


def Crossingover(parents: list):
    'Birth algorithm'
    s0 = len(parents[0].genes)
    s1 = len(parents[1].genes)
    cut_place = int(min(s0, s1) * random.random())
    return parents[0].genes[0:cut_place] + parents[1].genes[cut_place:]


def ChangeGenes(genom, mutation_rate):
    'Mutation algorithm'
    mutation_amount = 0
    for i in range(len(genom.genes)):
        if random.random() < mutation_rate:
            genom.genes[i] = random.choice(genom.possible_genes)
            mutation_amount += 1
    return mutation_amount

def ChangeGenesAddNew(genom, mutation_rate):
    'Mutation algorithm'
    mutation_amount = 0
    for i in range(len(genom.genes)):
        if random.random() < mutation_rate:
            genom.genes[i] = random.choice(genom.possible_genes)
            mutation_amount += 1
    # inversion
    if random.random() < mutation_rate:
        a = int(random.random() * len(genom.genes))
        b = int(random.random() * len(genom.genes))
        if a > b:
            a,b = b,a
        mid = genom.genes[a:b]
        mid.reverse()
        genom.genes = genom.genes[0:a] + mid + genom.genes[b:]
        mutation_amount += b-a
    # duplication
    if random.random() < mutation_rate:
        a = int(random.random() * len(genom.genes))
        b = int(random.random() * len(genom.genes))
        if a > b:
            a,b = b,a
        mid = genom.genes[a:b]
        genom.genes = genom.genes[0:a] + mid * 2 + genom.genes[b:]
        mutation_amount += b-a
    # delete
    if random.random() < mutation_rate:
        a = int(random.random() * len(genom.genes))
        b = int(random.random() * len(genom.genes)) + 1
        if a > b:
            a,b = b,a
        mid = genom.genes[a:b]
        if len(mid) < len(genom.genes):
            genom.genes = genom.genes[0:a] + genom.genes[b:]
            mutation_amount += b-a
    return mutation_amount


class Genom:
    def __init__(self, amount_of_genes=-1, possible_genes=[0, 1],
                 parents=[None], birth_algorithm=Crossingover,
                 mutation_rate=0.1, mutation_algorithm=ChangeGenesAddNew,
                 custom_genom=[]):
        if amount_of_genes == -1 and parents==[None] and custom_genom==[]:
            raise ValueError('Either amount_of_genes or parents or' +\
                             'custom_genom must be set')
        if custom_genom != []:
            self.possible_genes = possible_genes
            self.genes = custom_genom
        elif amount_of_genes != -1:
            self.possible_genes = possible_genes
            self.genes = [random.choice(self.possible_genes)
                                      for i in range(amount_of_genes)]
            mutation_algorithm(self, mutation_rate)
        elif parents != [None]:
            self.possible_genes = list(set(parents[0].possible_genes).union(
                                            set(parents[1].possible_genes)))
            self.genes = birth_algorithm(parents)
            mutation_algorithm(self, mutation_rate)

    def to_str(self):
        return str(self.genes)


COLOR_MUTATION_RATE = [32, 2, 0.125]
class Unit:
    def __init__(self, amount_of_genes=-1, possible_genes=[0, 1],
                 parents=[None], birth_algorithm=Crossingover,
                 mutation_rate=0.1, mutation_algorithm=ChangeGenesAddNew,
                 color=(-1,-1,-1), weight=-1, custom_genom=[]):
        self.ready_to_mate = False
        if custom_genom != []:
            self.genom = Genom(amount_of_genes=amount_of_genes,
                               possible_genes=possible_genes,
                               parents=[None],
                               birth_algorithm=birth_algorithm,
                               mutation_rate=mutation_rate,
                               mutation_algorithm=mutation_algorithm,
                               custom_genom=custom_genom)
        else:
            parents_genom=[None]
            if parents!=[None]:
                parents_genom = [parents[0].genom,parents[1].genom]
            self.genom = Genom(amount_of_genes=amount_of_genes,
                               possible_genes=possible_genes,
                               parents=parents_genom,
                               birth_algorithm=birth_algorithm,
                               mutation_rate=mutation_rate,
                               mutation_algorithm=mutation_algorithm)
        if weight == -1:
            self.weight = 100 + 50 * random.random()
        else:
            self.weight = weight
        self.cursor = 0
        if color != (-1,-1,-1):
            self.color = color
        elif parents==[None]:
            self.color = (256*random.random(),
                          256*random.random(),
                          256*random.random())
        else:
            self.color = ((parents[0].color[0]+parents[1].color[0])/2,
                          (parents[0].color[1]+parents[1].color[1])/2,
                          (parents[0].color[2]+parents[1].color[2])/2)
        self.age = 0
        new_color = list(self.color)
        for i in range(3):
            new_color[i] =\
                        min(255, max(0, self.color[i]+(random.random()-0.5)*\
                                     COLOR_MUTATION_RATE[i]))
        self.color = (new_color[0], new_color[1], new_color[2])

    def to_str(self):
        ans = ""
        ans += str(self.ready_to_mate) + "," +\
                str(self.weight) + "," +\
                str(self.cursor) + "," +\
                str(self.age) + "," +\
                str(self.color) + "," +\
                str(self.genom.to_str())
        return ans


class Food:
    def __init__(self, weight=10):
        self.weight = weight
        self.color = (256*random.random(),
                     256*random.random(),
                     256*random.random())


class Environment:
    def __init__(self):
        self.current_tick = 0
        self.torus = True
        self.width = 1500
        self.height = 800
        self.newborn_average = 50
        self.newborn_d = 25
        self.unit_max_weight = 200*1000
        self.food_rate = 1 / 2
        self.food_start_weight = 15
        self.born_by_division = 0
        self.born_by_mating = 0
        self.genofond = list(map(str, range(0, 30)))
        self.population_size = 20
        self.population =\
                    [Unit(amount_of_genes=12, possible_genes=self.genofond)
                     for i in range(self.population_size)]
        for unit in self.population:
            unit.x = self.width * random.random()
            unit.y = self.height * random.random()
        self.canteen_size = 400
        self.canteen =\
                    [Food(weight=self.food_start_weight)
                     for i in range(self.canteen_size)]
        for food in self.canteen:
            food.x = self.width * random.random()
            food.y = self.height * random.random()

    def pop_unit(self, i):
        self.population = self.population[0:i] + self.population[i+1:]
        self.population_size -= 1

    def pop_food(self, i):
        self.canteen = self.canteen[0:i] + self.canteen[i+1:]
        self.canteen_size -= 1

    def fix_all_dead_end(self):
        ans = 0
        i = 0
        while i < self.population_size:
            tupic = True
            for gen in self.population[i].genom.genes:
                if int(gen) % 10 == 6 or int(gen) % 10 == 7:
                    tupic = False
            if tupic:
                ans += 1
                self.population[i].genom.genes = random.choice([['7'], ['6']]) +\
                                                 self.population[i].genom.genes
            i += 1
        return ans
    def delete_all_dead_end(self):
        ans = 0
        i = 0
        while i < self.population_size:
            tupic = True
            for gen in self.population[i].genom.genes:
                if int(gen) % 10 == 6 or int(gen) % 10 == 7:
                    tupic = False
            if tupic:
                ans += 1
                self.pop_unit(i)
                i -= 1
            i += 1
        return ans

    def count_ready_to_mate(self):
        ans = 0
        for unit in self.population:
            if unit.ready_to_mate:
                ans += 1
        return ans

    def add_custom_unit(self, new_genom, new_color):
        self.population.append(
            Unit(possible_genes=self.genofond,
                 custom_genom=new_genom))
        self.population_size += 1
        self.population[-1].x = self.width * random.random()
        self.population[-1].y = self.height * random.random()
        self.population[-1].weight = 1000
        self.population[-1].color = tuple(new_color)

    def add_random_unit(self):
        self.population.append(
            Unit(amount_of_genes=12, possible_genes=self.genofond))
        self.population_size += 1
        self.population[-1].x = self.width * random.random()
        self.population[-1].y = self.height * random.random()
        self.population[-1].weight = 100
        self.population[-1].color = (256*random.random(),
                                     256*random.random(),
                                     256*random.random())

    def tick(self):
        COEF_TO_READY_TO_MATE = 2
        
        self.current_tick += 1
        if self.current_tick % max(1, int(1 / self.food_rate)) == 0:
            self.canteen.append(Food(weight=self.food_start_weight))
            self.canteen[-1].x = self.width * random.random()
            self.canteen[-1].y = self.height * random.random()
        i = 0
        while i < self.population_size:
            unit = self.population[i]
            unit.age += 1
            unit.weight -= 0.04 + (unit.weight / 100)**2 / 3 +\
                           math.sqrt(len(unit.genom.genes)) * 0.015
            
            cur_gen = unit.genom.genes[unit.cursor]
            next_gen =\
                int(unit.genom.genes[(unit.cursor+1) % len(unit.genom.genes)])
            disp = (next_gen / len(self.genofond) - 0.5) * self.newborn_d
            if unit.weight <=\
                   COEF_TO_READY_TO_MATE * (self.newborn_average + disp):
                unit.ready_to_mate = False
    
            if int(cur_gen) % 10 == 0:
                unit.x -= next_gen
                unit.weight -= 0.002 * next_gen
            if int(cur_gen) % 10 == 1:
                unit.y -= next_gen
                unit.weight -= 0.002 * next_gen
            if int(cur_gen) % 10 == 2:
                unit.x += next_gen
                unit.weight -= 0.002 * next_gen
            if int(cur_gen) % 10 == 3:
                unit.y += next_gen
                unit.weight -= 0.002 * next_gen
            if int(cur_gen) % 10 == 4:
                ans_j = -1
                ans_dist = 1000000000
                for j in range(len(self.canteen)):
                    new_dist =(unit.x-self.canteen[j].x)**2 +\
                              (unit.y-self.canteen[j].y)**2
                    if  new_dist < ans_dist:
                        ans_dist = new_dist
                        ans_j = j
                if abs(unit.x - self.canteen[ans_j].x) >\
                   abs(unit.y - self.canteen[ans_j].y):
                    if unit.x - self.canteen[ans_j].x > 0:
                        unit.cursor = (unit.cursor + 0) % len(unit.genom.genes)
                    else:
                        unit.cursor = (unit.cursor + 4) % len(unit.genom.genes)
                else:
                    if unit.y - self.canteen[ans_j].y > 0:
                        unit.cursor = (unit.cursor + 2) % len(unit.genom.genes)
                    else:
                        unit.cursor = (unit.cursor + 6) % len(unit.genom.genes)
            if int(cur_gen) % 10 == 5:
                unit.cursor = (unit.cursor + next_gen) % len(unit.genom.genes)
            if unit.weight <= 0:
                self.pop_unit(i)
                continue
            radius = math.sqrt(unit.weight)
            if int(cur_gen) % 10 == 6:
                disp = (next_gen / len(self.genofond) - 0.5) * self.newborn_d  
                if unit.weight > 2.5 * (self.newborn_average + disp):
                    self.born_by_division += 1
                    unit.ready_to_mate = False
                    self.population.append(
                        Unit(parents=[unit,unit],
                             weight=self.newborn_average + disp))
                    self.population_size += 1
                    self.population[-1].x = unit.x + 3 * radius *\
                                                        (random.random()-0.5)
                    self.population[-1].y = unit.y + 3 * radius *\
                                                        (random.random()-0.5)
                    unit.weight -= self.newborn_average + disp
            if int(cur_gen) % 10 == 7:
                disp = (next_gen / len(self.genofond) - 0.5) * self.newborn_d  
                if unit.weight > COEF_TO_READY_TO_MATE *\
                                       (self.newborn_average + disp):
                    unit.ready_to_mate = True

            if unit.ready_to_mate:
                for j in range(len(self.population)):
                    if i == j:
                        continue
                    unit2 = self.population[j]
                    distance = math.sqrt((unit.x-unit2.x)**2+\
                                         (unit.y-unit2.y)**2)
                    color_distance = abs(unit.color[2]-unit2.color[2])
                    #if unit2.ready_to_mate: #DBG distance
                    #if unit2.ready_to_mate and color_distance <= 5:
                    if unit2.ready_to_mate and distance < radius * 10 and\
                                                color_distance <= 5:
                        self.born_by_mating += 1
                        unit.ready_to_mate = False
                        unit2.ready_to_mate = False
                        self.population.append(
                                Unit(parents=[unit,unit2],
                                     weight=self.newborn_average + disp))
                        self.population_size += 1
                        self.population[-1].x = (unit.x+unit2.x)/2 +\
                                                        3 * radius *\
                                                        (random.random()-0.5)
                        self.population[-1].y = (unit.y+unit2.y)/2 +\
                                                        3 * radius *\
                                                        (random.random()-0.5)
                        unit.weight -= (self.newborn_average + disp) / 2
                        unit2.weight -= (self.newborn_average + disp) / 2

            if self.torus:
                if unit.x < 0:
                    unit.x += self.width
                if unit.y < 0:
                    unit.y += self.height
                if unit.x >= self.width:
                    unit.x -= self.width
                if unit.y >= self.height:
                    unit.y -= self.height
            else:
                if unit.x < 0:
                    unit.x = -unit.x
                if unit.y < 0:
                    unit.y = -unit.y
                if unit.x >= self.width:
                    unit.x = 2*self.width - unit.x
                if unit.y >= self.height:
                    unit.y = 2*self.height - unit.y
            if unit.weight < self.unit_max_weight:
                j = 0
                while j < len(self.canteen):
                    if (unit.x-self.canteen[j].x)**2 +\
                           (unit.y-self.canteen[j].y)**2 <\
                           (radius + math.sqrt(self.canteen[j].weight))**2:
                        unit.weight += self.canteen[j].weight
                        self.pop_food(j)
                        continue
                    j += 1
            unit.cursor = (unit.cursor + 1) % len(unit.genom.genes)
            i += 1

    def to_str(self):
        ans = ""
        ans += str(self.current_tick) + "," +\
                str(self.torus) + "," +\
                str(self.width) + "," +\
                str(self.height) + "," +\
                str(self.newborn_average) + "," +\
                str(self.newborn_d) + "," +\
                str(self.unit_max_weight) + "," +\
                str(self.food_rate) + "," +\
                str(self.food_start_weight) + "," +\
                str(self.born_by_division) + "," +\
                str(self.born_by_mating) + "," +\
                str(self.genofond) + "," +\
                str(self.population_size) + "\n"
        for unit in self.population:
            ans += "\n" + unit.to_str()
        return ans
            

def save(env, i):
    f = open("save" + str(i) + ".txt", 'w')
    f.write(env.to_str())
    f.close()



if __name__ == '__main__':
    #Unit1 = Unit(amount_of_genes=5, possible_genes=[0,1,'a','b'])
    #Unit2 = Unit(amount_of_genes=8, possible_genes=[0,1,'a','b'])
    #Unit3 = Unit(parents=[Unit1,Unit2])

    pygame.init()
    env = Environment()
    screen = pygame.display.set_mode([env.width, env.height])
    running = True
    fast = False
    info = False
    pause = False
    super_fast = False
    next_step = False
    add_random_cells = False
    vacinated = -1
    last_born_by_mating = 0
    last_born_by_division = 0
    while running:
        if env.current_tick == 0:
            env.add_custom_unit(list(map(str,[21,21,27,2,23,14,20,25])),
                                        (255,0,0))
            env.add_custom_unit(list(map(str,[21,21,27,2,23,14,20,25])),
                                        (255,0,0))
            env.add_custom_unit(list(map(str,[21,25,27,2,23,14,20,20])),
                                        (0,255,129))
            env.add_custom_unit(list(map(str,[21,25,27,2,23,14,20,20])),
                                        (0,255,127))
            env.add_custom_unit(list(map(str,[21,21,16,2,23,24,20,25])),
                                        (0,0,255))
            env.add_custom_unit(list(map(str,[21,21,16,2,23,24,20,25])),
                                        (0,0,255))
        if env.current_tick > 0 and env.current_tick % 100000 == 0:
            save(env, env.current_tick // 100000)
        if env.current_tick % 1000 == 0:
            vacinated = env.fix_all_dead_end()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_f:
                    fast = not fast
                    super_fast = False
                if event.key == pygame.K_s:
                    super_fast = not super_fast
                    if super_fast == False:
                        fast = False
                if event.key == pygame.K_i:
                    info = not info
                if event.key == pygame.K_p:
                    pause = not pause
                if event.key == pygame.K_n:
                    next_step = True
                if event.key == pygame.K_r:
                    add_random_cells = not add_random_cells
                if event.key == pygame.K_g:
                    env.delete_all_dead_end()
                if event.key == pygame.K_a:
                    new_genom = list(
                                input("Genom (format 1,0,2): ").split(",")
                                )
                    new_color = list(map(int,
                                input("Color (format 0,100,200): ").split(",")
                                ))
                    env.add_custom_unit(new_genom, new_color)
        if pause and not next_step:
            continue
        next_step = False
        screen.fill((255, 255, 255))

        if fast or super_fast:
            env.tick()
            while env.current_tick % (1000 if super_fast else 10) != 0:
                env.tick()
        else:
            env.tick()

        if add_random_cells and env.current_tick % 10000 == 0:
            sz = env.population_size
            while env.population_size <= sz * 1.2:#40:
                env.add_random_unit()

        pygame.display.set_caption('Units alive: ' + str(env.population_size) +
                                   ', tick number ' + str(env.current_tick) +
                                   '. Vaccinated: ' + str(vacinated) +
                                   '. Born by division: ' +
                                   str(env.born_by_division) +
                                   ' (+' + str(env.born_by_division-\
                                               last_born_by_division) +
                                   '). Born by mating: ' +
                                   str(env.born_by_mating) +
                                   ' (+' + str(env.born_by_mating-\
                                               last_born_by_mating) +
                                   ')')
        last_born_by_mating = env.born_by_mating
        last_born_by_division = env.born_by_division
        for unit in env.population:
            pygame.draw.circle(screen, unit.color, (unit.x, unit.y),
                               math.sqrt(unit.weight))
            if unit.ready_to_mate:
                pygame.draw.circle(screen, (255,255,255), (unit.x, unit.y),
                               math.sqrt(unit.weight)/3)
            if info:
                fontsize = 2*int(math.sqrt(unit.weight))
                font = pygame.font.SysFont('monospace', fontsize)
                text = font.render(str(unit.age)+','+\
                                   str(len(unit.genom.genes))+' '+\
                                   str(unit.cursor)+':'+\
                                   str(unit.genom.genes[unit.cursor]),
                                       True, (0, 0, 0))
                screen.blit(text, (unit.x, unit.y-fontsize))
                text = font.render(",".join(unit.genom.genes),
                                       True, (0, 0, 0))
                screen.blit(text, (unit.x, unit.y))
        for food in env.canteen:
            pygame.draw.circle(screen, food.color, (food.x, food.y),
                               math.sqrt(food.weight))

        pygame.display.flip()

    pygame.quit()

#                     14,1,15,16,11,12,15,3,13,10 <- best ever
#  best ever mutated: 24,21,15,16,11,22,25,3,22,20
#                     24,7,15,16,11,22,25,13,26,20
#                     24,21,15,16,11,22,25,13,24,20
#                     24,20,15,7,11,22,25,3,13,19
#4,15,7,15,7,15,9,15,9,0,20,1,20,15,5,2,17,3,17,6,6 An1
#4,0,15,1,16,1 An2
#16,1,24,0,24,1 AnEv (24,0,24,7,16,1) (14,2,16,1)
# 3,14,10,14,12,19,12,12,26 <- good
#
#17,1,21,26,22,23,14,12
#4,1,21,29,22,23,14,6
#
#
#14,20,13,15,27,22,22,14,0,25,21,21 <- 400000 ticks (after 10 millions of evo)
#     gen engineering 14,20,13,15,27,22,22,14,0,25,21,27
#ADD                  14,5,13,25,27,28,12,14,20,25,21,21 <- 200000
#ADD                  14,12,3,25,27,22,22,14,20,25,21,20 <- 100000
#14,17,13,25,27,22,22,14,20,25,21,20
#14,17,13,25,27,28,12,14,20,25,21,21
#
#24,15,13,27,5,16,12,24,0,25,21,21 (after 20 million of evo)
#
#
# 36 million of evo:
#  21,21,27,2,23,14,20,25
#  21,25,27,2,23,14,20,20
#  21,21,16,2,23,24,20,25
