olution_clock::now(); // Arrêter le chronomètre
     auto duration = duration_cast<microseconds>(stop - start);
     cout << "Temps d'execution : " << duration.count() << " microsecondes" << endl;

    start = high_resolution_clock::now(); // Démarrer le chronomètre
    cout << "Le resultat iteratif est : " << fibonacci_iteratif(val) << endl;
    stop = high_resolution_clock::now(); // Arrêter le chronomètre
    duration = duration_cast<