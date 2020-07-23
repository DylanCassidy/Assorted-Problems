using System.Collections.Generic;

class MainClass 
{
	public static void Main (string[] args) 
	{
		char[][] triplets = new char[][] {
			new char[] {'t','u','p'},
			new char[] {'w','h','i'},
			new char[] {'t','s','u'},
			new char[] {'a','t','s'},
			new char[] {'h','a','p'},
			new char[] {'t','i','s'},
			new char[] {'w','h','s'}
		};

		System.Console.WriteLine(SecretSolver(triplets));
	}

	public static string SecretSolver(char[][] triplets)
	{
		// initial set up
		List<char> secret = new List<char>();
		List<char> possible = new List<char>();
		List<char> notPossible = new List<char>();
		foreach(char[] set in triplets)
		{
			// the first char of each set is in consideration for being the next secret letter
			if(!possible.Contains(set[0]))
			{
				possible.Add(set[0]);
			}

			// all other chars of each set cannot possibly be the next secret letter
			for(int j = 1; j < set.Length - 1; ++j)
			{
				notPossible.Add(set[j]);
			}
		}

		// secret solver algorithm
		int i = 0;
		while(possible.Count > 0)
		{
			if(notPossible.Contains(possible[i]))
			{
				i++;

				if(possible.Count > i) { continue; }
				// should never happen if the secret is solvable.
				// make sure that this logs an error.
				else { break; }
			}

			char newSecret = possible[i];
			secret.Add(newSecret);
			possible.Remove(newSecret);

			// repopulate the possible and notPossible sets
			foreach(char[] set in triplets)
			{
				for(int j = 0; j < set.Length - 1; ++j)
				{
					if(set[j] != newSecret) { continue; }

					char newPossible = set[j+1];

					if(!possible.Contains(newPossible))
					{
						possible.Add(newPossible);
					}
					
					notPossible.Remove(newPossible);
				}
			}

			i = 0;
		}

		// creating new strings results in an allocation
		// this ensures that we only do that allocation once
		return new string(secret.ToArray());
	}
}