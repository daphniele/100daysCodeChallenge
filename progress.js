let progress = 0;  // Inicializa o progresso como 0

// Função para atualizar a barra de progresso
function updateProgressBar() {
    const progressBarFull = document.getElementById('progressBarFull');
    if(progress <= 100) {  // Verifica se o progresso é menor ou igual a 100
        progressBarFull.style.width = progress + '%';  // Atualiza a largura da barra de progresso
    }
}

// Função para verificar se um link do GitHub foi adicionado
function checkForGitHubLink(mutationsList, observer) {
    for(let mutation of mutationsList) {
        if(mutation.type === 'childList') {
            const links = mutation.target.querySelectorAll('a');
            for(let link of links) {
                if(link.href.includes('github.com')) {
                    progress += 1;  // Incrementa o progresso
                    updateProgressBar();  // Atualiza a barra de progresso
                }
            }
        }
    }
}

// Cria um observer para observar mudanças nos elementos <p>
const observer = new MutationObserver(checkForGitHubLink);

// Começa a observar os elementos <p> dentro dos elementos <summary>
const summaries = document.querySelectorAll('summary');
for(let summary of summaries) {
    const paragraphs = summary.querySelectorAll('p');
    for(let paragraph of paragraphs) {
        observer.observe(paragraph, { childList: true });
    }
}
