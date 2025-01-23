# Erklärung des HTML-Skripts

Dieses HTML-Dokument zeigt, wie man den Inhalt eines Absatz-Tags durch Klicken auf einen Button ändern kann.

## Struktur des Dokuments

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ändern des Inhalts eines Absatz-Tags</title>
</head>
<body>
    <h1>Ändern des Inhalts eines Absatz-Tags</h1>
    <p id="text">Das ist ein Beispiel text.</p>
    <button id="changeButton">Button</button>
    <script>
        // Funktion zum Ändern des Textinhalts des Paragraphen
        function changeText() {
            // Paragraph-Element mit der ID 'text' abrufen
            const paragraph = document.getElementById("text");
            paragraph.textContent = "Dies ist ein neuer Text.";
        }

        // Event-Listener für den Button hinzufügen
        document.getElementById("changeButton").addEventListener("click", changeText);
    </script>
</body>
</html>
```

### Erklärung der einzelnen Abschnitte

1. **DOCTYPE und HTML-Tag**:
    ```html
    <!DOCTYPE html>
    <html lang="en">
    ```
    Diese Zeilen definieren den Dokumenttyp als HTML5 und setzen die Sprache des Dokuments auf Englisch.

2. **Head-Bereich**:
    ```html
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Ändern des Inhalts eines Absatz-Tags</title>
    </head>
    ```
    Der Head-Bereich enthält Metadaten über das Dokument, wie die Zeichencodierung (UTF-8), die Viewport-Einstellungen für responsives Design und den Titel des Dokuments.

3. **Body-Bereich**:
    ```html
    <body>
        <h1>Ändern des Inhalts eines Absatz-Tags</h1>
        <p id="text">Das ist ein Beispiel text.</p>
        <button id="changeButton">Button</button>
    ```
    Der Body-Bereich enthält den sichtbaren Inhalt der Seite. Hier gibt es eine Überschrift (`<h1>`), einen Absatz (`<p>`) mit der ID "text" und einen Button (`<button>`) mit der ID "changeButton".

4. **Script-Bereich**:
    ```html
    <script>
        // Funktion zum Ändern des Textinhalts des Paragraphen
        function changeText() {
            // Paragraph-Element mit der ID 'text' abrufen
            const paragraph = document.getElementById("text");
            paragraph.textContent = "Dies ist ein neuer Text.";
        }

        // Event-Listener für den Button hinzufügen
        document.getElementById("changeButton").addEventListener("click", changeText);
    </script>
    ```
    Der Script-Bereich enthält JavaScript-Code, der die Funktionalität der Seite steuert. Die `changeText`-Funktion ändert den Textinhalt des Absatzes mit der ID "text". Ein Event-Listener wird hinzugefügt, um die `changeText`-Funktion auszuführen, wenn der Button mit der ID "changeButton" geklickt wird.

5. **Alternatives Script**:
   ```html
       <script>
        // Funktion zum Ändern des Textinhalts des Paragraphen
        function changeText() {
            // Paragraph-Element mit der ID 'text' abrufen
            const paragraph = document.getElementById("text");

            if (paragraph.textContent === "Das ist ein Beispiel text.") {
                paragraph.textContent  =  "Dies ist ein neuer Text.";
            } else {
                paragraph.textContent = "Das ist ein Beispiel text.";
            }
        }

        // Event-Listener für den Button hinzufügen
        document.getElementById("changeButton").addEventListener("click", changeText);
    </script>
    ```
    In diesem Script-Bereich wird durch erneutes Drücken des buttons der Inhalt des Absatzes wieder zum Original Geändert.

6. **Schließende Tags**:
    ```html
    </body>
    </html>
    ```
    Diese Zeilen schließen die Body- und HTML-Tags und beenden das Dokument.
