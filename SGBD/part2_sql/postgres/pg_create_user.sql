/*
REQUETE ADMIN => Créer un nouvel utilisateur/schéma (chokri) + privileges
 */
select
    current_user;

select
    current_database ();

CREATE ROLE chokri LOGIN PASSWORD 'motdepasse';

CREATE SCHEMA IF NOT EXISTS chokri AUTHORIZATION chokri;

GRANT CONNECT ON DATABASE pise TO chokri;

GRANT USAGE ON SCHEMA chokri to chokri;

GRANT ALL PRIVILEGES ON ALL TABLES IN SCHEMA chokri TO chokri;